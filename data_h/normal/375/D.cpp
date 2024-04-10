#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;


#include <cstdio>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>

#define foreach(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); ++ i)

const int N = 111111;

int n, m, color[N];
int result[N];
int father[N];

vector<pair<int, int> > q[N];
vector<int> e[N];
map<int, int> mp[N];

struct Node;

Node* null;

struct Node {
    int key, weight, count, size;
    Node* children[2];

	Node() {
	}

    Node(int key, int count) : key(key), weight(rand()), count(count) {
        children[0] = children[1] = null;
        update();
    }

    void update() {
        size = children[0]->size + count + children[1]->size;
    }

    int query(int k) {
        if (this == null) {
            return 0;
        }
        if (key < k) {
            return children[1]->query(k);
        }
        return children[0]->query(k) + count + children[1]->size;
    }
};

Node* tree[N];

void rotate(Node *&x, int t) {
    Node *y = x->children[t];
    x->children[t] = y->children[t ^ 1];
    y->children[t ^ 1] = x;
    x->update();
    y->update();
    x = y;
}

void insert(Node *&v, int key, int delta) {
    if (v == null) {
        v = new Node(key, delta);
    } else if (v->key == key) {
        v->count += delta;
    } else {
        int t = v->key < key;
        insert(v->children[t], key, delta);
        if (v->children[t]->weight < v->weight) {
            rotate(v, t);
        }
    }
    v->update();
}


void combinate(int y, int x) {
	if (mp[y].size() > mp[x].size()) {
		mp[y].swap(mp[x]);
		swap(tree[x], tree[y]);
	}
	
	for(map<int, int> :: iterator it = mp[y].begin(); it != mp[y].end(); ++it) {
		if (mp[x].count(it->first)) {
			insert(tree[x], mp[x][it->first], -1);
		}
		mp[x][it->first] += it->second;
		insert(tree[x], mp[x][it->first], 1);
	}
}

void dfs(int x) {
	
	tree[x] = new Node(1, 1);
	mp[x][color[x]] = 1;
	
	for(int i = 0; i < (int)e[x].size(); i++) {
		int y = e[x][i];
		if (y == father[x])
			continue;
		father[y] = x;
		dfs(y);
		combinate(y, x);
	}
	
	for(int i = 0; i < (int)q[x].size(); i++) {
		result[q[x][i].second] = tree[x]->query(q[x][i].first);
	}
	
}

int main() {
    null = new Node;
    null->key = null->count = 0;
    null->size = 0;
    null->weight = INT_MAX;
    null->children[0] = null->children[1] = null;
    scanf("%d%d", &n, &m);
    
    for(int i = 1; i <= n; i++) {
    	scanf("%d", &color[i]);
    }
    
    for(int i = 1; i < n; i++) {
    	int a, b;
    	scanf("%d %d", &a, &b);
    	e[a].push_back(b);
    	e[b].push_back(a);
    }
    
    for (int i = 1; i <= m; ++ i) {
        int a, b;
        scanf("%d%d", &a, &b);
        q[a].push_back(make_pair(b, i));
    }
    
    father[1] = 0;
    dfs(1);
    
    for(int i = 1; i <= m; i++) {
    	printf("%d\n", result[i]);
    }
    return 0;
}
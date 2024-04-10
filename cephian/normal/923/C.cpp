#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

struct node {
	int count = 0;
	node* child[2] = {0,0};
};

node* root = 0;

void add(node** r, int x, int i) {
	if(*r == 0) {
		*r = new node();
	}
	++(**r).count;
	if(i == -1) return;
	add(&(**r).child[(x&(1<<i))>0],x,i-1);
}

int match(node* r, int x, int i) {
	// cout <<i << endl;
	--r->count;
	if(i == -1) return x;
	bool b = (x&(1<<i))>0;
	if(r->child[b] && r->child[b]->count) {
		return match(r->child[b],x^((int(b)<<i)),i-1);
	} else {
		return match(r->child[!b],x^((int(!b)<<i)),i-1);
	}
}

const int N = 3e5+5;
int a[N],p[N];

int main() {
	fio;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	for(int i = 0; i < n; ++i) {
		cin >> p[i];
		add(&root,p[i],29);
	}
	for(int i = 0; i < n; ++i) {
		cout << match(root,a[i],29) << " ";
	}
	cout << "\n";
}
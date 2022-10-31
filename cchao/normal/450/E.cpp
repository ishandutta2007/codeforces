#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 10;
bitset<maxn> b;
typedef pair<int, int> pii;
vector<pii> v;
queue<int> q;

vector<int> prime;
void gen(int n) {
    prime.push_back(2);
    bitset<maxn> vis;
    for(int i = 3; i <= n; i += 2)
        if(!vis.test(i)) {
            prime.push_back(i);
            for(int j = i, k = i+i; j <= n; j += k)
                vis.set(j);
        }
}


int main() {
    int n; cin >> n;
    gen(n);
    for(int i = prime.size()-1; i >= 0; --i) {
        int p = prime[i];
        for(int j = p; j <= n; j += p) {
            if(!b.test(j)) q.push(j);
        }
        if(q.size()&1) {
            for(int j = 0; j < 2; ++j) {
                q.push(q.front()); q.pop();
            }
        }
        while(q.size() >= 2) {
            int x = q.front(); q.pop(); 
            int y = q.front(); q.pop();
            b.set(x); b.set(y);
            v.push_back(make_pair(x, y));
        }
        if(q.size()) q.pop();
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); ++i)
        cout << v[i].first << ' ' << v[i].second << endl;
    return 0;
}
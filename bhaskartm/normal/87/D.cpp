#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define ll long long
const int N = 1e5+5;
struct yal { int a, b, i; };
struct S { int to, i; };
map<int, vector<yal> > mp;
map<ll, vector<int> > ans;
vector<S> adj[N];
vector<int> v;
int D[N], n;
ll SZ[N], AH[N];
int get(int a) { return(!D[a]?a:D[a]=get(D[a])); }
void merg(int a, int b){
    a = get(a); b = get(b);
    SZ[a]+=SZ[b];
    D[b] = a;
}
ll DFS(int u, int p, int i){
    AH[i] = SZ[u];
    for(S x:adj[u]) if(x.to^p) AH[i]+=DFS(x.to, u, x.i);
    adj[u].clear();
    v.push_back(i);
    return(AH[i]);
}
int main(){
    fill(SZ, SZ+N, 1);
    scanf("%d", &n);
    for(int i=1;i<n;i++){
        int a, b, d; scanf("%d %d %d", &a, &b, &d);
        yal y = {a, b, i};
        mp[d].push_back(y);
    }
    for(auto x:mp){
        set<int> st;
        for(yal y:x.S){
            int a = get(y.a), b = get(y.b);
            S s = {b, y.i};
            adj[a].push_back(s);
            s.to = a;
            adj[b].push_back(s);
            st.insert(a);
        }
        for(int z:st) if(adj[z].size()){
            int sz = DFS(z, 0, 0);
            for(int ah:v) ans[-2*AH[ah]*(sz-AH[ah])].push_back(ah);
            v.clear();
        }
        for(yal y:x.S) merg(y.a, y.b);
    }
    printf("%lld %d\n", -(ans.begin()->F), (int)(ans.begin()->S).size());
    sort((ans.begin()->S).begin(), (ans.begin()->S).end());
    for(int x:(ans.begin()->S)) printf("%d ", x);
}
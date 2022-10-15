#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vpi;
typedef set<ll> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 998244353;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 200100
#define MAXL 19

int perm[MAXN];
int ind[MAXN];
int p[MAXN][MAXL];
int A[MAXN];
int fst[MAXN];
int L,N,Q,a,b;
int minres[MAXN];

int fd(int x, int h){
    for (int i=0;i<MAXL;++i){
        if ((1<<i) & h){
            if (p[x][i] == -1)return -1;
            x = p[x][i];
        }
    }
    return x;
}

struct SparseTable{
    int N,K;
    vector<vi> ST;
    SparseTable(int _N):N(_N){
        K = MSB(N);
        ST.resize(K);
        ST[0] = vi(minres,minres+N);
        for (int k=1;k<K;++k){
            for (int i=0;i+(1<<k)<=N;++i){
                ST[k].pb(min(ST[k-1][i], ST[k-1][i+(1<<(k-1))]));
            }
        }
        // for (int k=0;k<K;++k){
            // for(int i=0;i+(1<<k)<=N;++i)cout<<ST[k][i]<<' ';cout<<'\n';
        // }
        // cout<<"Over\n";
    }
    inline int MSB(int x){return 32-__builtin_clz(x);}
    int query(int x, int y){
        int k = MSB(y-x+1)-1;
        // cout<<k<<' '<<x<<' '<<y-(1<<k)+1<<'\n';
        return min(ST[k][x], ST[k][y - (1<<k) + 1]);
    }
}*S;

int main(){
    // freopen("in.txt","r",stdin);
    cin>>L>>N>>Q;
    for (int i=1;i<=L;++i){
        cin>>perm[i];
        ind[perm[i]] = i;
    }
    for (int i=1;i<=N;++i){
        cin>>A[i];
    }
    memset(fst,-1,sizeof(fst));
    memset(p,-1,sizeof(p));
    for (int i=N;i>=1;--i){
        int x = ind[A[i]];
        int t = x + 1;
        if (t == L+1)t = 1;
        t = perm[t];
        // cout<<"At index "<<i<<" next element is "<<t<<'\n';
        if (fst[t] != -1)p[i][0] = fst[t];
        fst[A[i]] = i;
    }
    
    // for (int i=1;i<=N;++i)cout<<p[i][0]<<' ';
    //     cout<<'\n';

    for (int j=1;j<MAXL;++j){
        for (int i=1;i<=N;++i){
            if (p[i][j-1] != -1){
                p[i][j] = p[p[i][j-1]] [j-1];
            }
        }
    }

    for (int i=1;i<=N;++i)minres[i] = fd(i, L-1);
    for (int i=1;i<=N;++i){
        if (minres[i] == -1)minres[i] = INF;
    }
    minres[0] = INF;
    // for (int i=0;i<N+1;++i)cout<<minres[i]<<' ';cout<<'\n';
    // return 0;
    S = new SparseTable(N+1);
    while(Q--){
        cin>>a>>b;
        // cout<<S->query(a,b)<<'\n';
        if (S->query(a,b) <= b)cout<<'1';
        else cout<<'0';
    }
}
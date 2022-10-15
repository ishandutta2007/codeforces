#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
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
#define MAXN 300100
#define MAXL 20

int lst[MAXL];
int frst[MAXN][MAXL];
int N,Q,a,b;
int A[MAXN];

bool query(int a, int b){
    for (int j=0;j<MAXL;++j){
        if (((1<<j) & A[b]) == 0)continue;
        int l = frst[a][j];
        if (l != -1 && l <= b)return 1;
    }
    return 0;
}

int main(){
    // freopen("in.txt","r",stdin);
    cin >>N>>Q;
    for (int i=1;i<=N;++i)cin>>A[i];
    memset(lst,-1,sizeof(lst));
    for (int i=1;i<=N;++i)for (int j=0;j<MAXL;++j)frst[i][j] = INF;
    for (int i=N; i>=1;--i){
        for (int j=0;j<MAXL;++j){
            if (((1<<j) & A[i]) == 0)continue;
            // i is on the path j.
            // cout<<"Node "<<i<<" on path " <<j<<'\n';
            frst[i][j]=i;
            int x = lst[j];
            if (x != -1){
                for (int k=0;k<MAXL;++k){
                    frst[i][k]  = min(frst[i][k], frst[x][k]);
                }
            }
            lst[j] = i;
        }
    }

    for (int i=1;i<=N;++i){
        for (int j=0;j<MAXL;++j)if (frst[i][j] == INF)frst[i][j] = -1;
    }

    // for (int i=1;i<=N;++i){
        // for (int j=0;j<MAXL;++j)cout<<frst[i][j]<<' ';
        // cout<<'\n';
    // }

    for (int i=0;i<Q;++i){
        cin >> a >> b;
        if (query(a,b))cout<<"Shi\n";
        else cout<<"Fou\n";
    }
}
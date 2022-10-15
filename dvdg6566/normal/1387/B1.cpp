#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vpi;
typedef long double ld;
#define pb emplace_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define ALL(x) x.begin(), x.end()
#define SZ(x) (ll)x.size()
#define f first
#define s second
const ll MOD = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 100010;

int N,a,b;
int A[MAXN];
queue<int> Q;
set<int> S[MAXN];
int fl=-1;
int O[MAXN];

int main(){
    cin>>N;
    for(int i=1;i<N;++i){
        cin>>a>>b;
        O[a]=b;
        O[b]=a;
        S[a].insert(b);S[b].insert(a);
    }
    for(int i=1;i<=N;++i){
        A[i]=i;
        if(SZ(S[i])==1)Q.push(i);
    }
    int ans=0;
    while(SZ(Q)){
        int x=Q.front();Q.pop();
        if(SZ(S[x])==0&&A[x]==x){
            swap(A[x],A[O[x]]);
            ans+=2;
            break;
        }
        int t=*S[x].begin();
        if(A[x]==x){
            ans+=2;
            swap(A[x],A[t]);
        }
        S[t].erase(x);
        S[x].erase(t);
        if(SZ(S[t])==1)Q.push(t);
    }
    cout<<ans<<'\n';
    for(int i=1;i<=N;++i){
        assert(A[i]!=i);
        cout<<A[i]<<' ';
    }
    cout<<'\n';
}
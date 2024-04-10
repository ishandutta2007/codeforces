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
const ll MAXN = 1100;
const ll INF = 1e18+10;
const ll MOD =  998244353;
ll N,M,W,a,b,c,d,e,K,T;
ll done[MAXN][MAXN];
ll A[MAXN][MAXN];
queue<pi> Q;
ll dx[]={1,-1,0,0};
ll dy[]={0,0,-1,1};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>N>>M>>T;
    for(ll i=0;i<N;++i){
        string S;cin>>S;
        for(ll j=0;j<M;++j)if(S[j]=='1')A[i][j]=1;
    }
    for(ll i=0;i<N;++i)for(ll j=0;j<M;++j)done[i][j]=INF;
    for(ll i=0;i<N;++i)for(ll j=0;j<M;++j){
        ll ok=0;
        for(ll k=0;k<4;++k){
            ll cx=i+dx[k];
            ll cy=j+dy[k];
            if(cx<0||cy<0||cx>=N||cy>=M)continue;
            if(A[cx][cy]==A[i][j])ok=1;
        }
        if(ok){done[i][j]=0;Q.push(mp(i,j));}
    }
    while(SZ(Q)){
        pi t=Q.front();Q.pop();
        ll x=t.f;
        ll y=t.s;
        for(ll k=0;k<4;++k){
            ll cx=x+dx[k];
            ll cy=y+dy[k];
            if(cx<0||cy<0||cx>=N||cy>=M)continue;
            if(done[cx][cy]!=INF)continue;
            // cerr<<"Hi\n";
            done[cx][cy]=done[x][y]+1;
            Q.push(mp(cx,cy));
        }
    }
    while(T--){
        ll x,y;
        cin>>x>>y>>c;
        --x;--y;
        if(c<=done[x][y]){
            cout<<A[x][y]<<'\n';
        }else{
            ll flip=c-done[x][y];
            cout<<(A[x][y]+flip)%2<<'\n';
        }
    }
    // for(ll i=0;i<N;++i)for(ll j=0;j<M;++j){
    //     cout<<done[i][j]<<' ';
    //     if(j+1==M)cout<<'\n';
    // }
}
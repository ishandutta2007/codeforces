#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
typedef vector<pi> vpi;
#define pb emplace_back
#define f first 
#define s second
#define mp make_pair
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound

const int MAXN=200100;

int xx,N,Q,a,b,c,d,e,K,M,A,B;
vi V[MAXN];
int G[MAXN];
ll T[MAXN];
set<int> S;

int main(){
    int c;cin>>c;
    while(c--){
        cin>>N;
        for(int i=1;i<=N;++i)V[i].clear();
        for(int i=1;i<=N;++i){
            cin>>G[i];
        }        
        for(int i=1;i<=N;++i){
            cin>>a;
            V[G[i]].pb(a);
        }
        for(int i=1;i<=N;++i)sort(ALL(V[i]));
        for(int i=1;i<=N;++i){
            for(int k=1;k<SZ(V[i]);++k){
                V[i][k]+=V[i][k-1];
            }
            if(SZ(V[i])){
                T[i]=V[i].back();
                S.insert(i);
            }
        }
        for(int i=1;i<=N;++i){
            ll ans=0;
            stack<int> bad;
            for(auto j:S){
                ans+=T[j];
                ll k=SZ(V[j])%i;
                if(k)ans-=V[j][k-1];
                if(SZ(V[j])==i){
                    bad.push(j);
                }
            }
            while(SZ(bad)){
                S.erase(bad.top());
                bad.pop();
            }
            cout<<ans<<' ';
        }
        cout<<'\n';
    }
}
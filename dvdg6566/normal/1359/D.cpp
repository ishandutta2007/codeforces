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
const ll MAXN=100100;
const ll MAXK=17;
const ll INF=2e18;
const ll MOD=998244353;

ll ans;
ll N,a;
ll A[MAXN];
ll sums[MAXN];
ll pref[MAXN];
ll post[MAXN];

void ask(int s, int e, int tar){
    if(e<s)return;
    vi indeces;
    for (int i=s;i<=e;++i){
        if(A[i]==tar)indeces.pb(i);
    }
    if (SZ(indeces)==0){ask(s,e,tar-1);return;}
    // cerr<<s<<' '<<e<<' '<<tar<<'\n';
    // prefix minimum and suffix maximum
    pref[s-1]=0;
    sums[s]=A[s];
    for(int i=s+1;i<=e;++i)sums[i]=sums[i-1]+A[i];
    for(int i=s;i<=e;++i)pref[i]=min(pref[i-1],sums[i]);
    post[e+1]=-INF;
    for(int i=e;i>=s;--i)post[i]=max(post[i+1],sums[i]);
    for (auto i:indeces){
        ll minus=pref[i-1];
        ll plus=post[i];
        // cerr<<plus-minus-tar<<'\n';
        ans=max(ans,plus-minus-tar);
    }
    ask(s,indeces[0]-1,tar-1);
    for(int i=0;i<SZ(indeces)-1;++i){
        int a=indeces[i];
        int b=indeces[i+1];
        ask(a+1,b-1,tar-1);
    }
    ask(indeces.back()+1,e,tar-1);
}

int main(){
    cin>>N;
    for(int i=1;i<=N;++i)cin>>A[i];
    ask(1,N,30);  
    cout<<ans;
}
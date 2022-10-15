#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll,ll> pi;
typedef pair<int,pi> pii;
typedef vector<pi> vpi;
typedef set<int> si;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define f first
#define s second
ll INF = 1e9;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 100100

ll N,M,D,a,b;
vpi A,B;
ll curwgt,cursgf,curindA,curindB,ans;

bool cmp(pi a, pi b){
    if (a.f == b.f)return a.s > b.s;
    return a.f < b.f;
}

int main(){
    // freopen("in.txt","r",stdin);
    cin>>N>>M>>D;
    for (int i=0;i<N;++i){
        cin>>a>>b;
        A.pb(mp(a,b));
    }
    for (int i=0;i<M;++i){
        cin>>a>>b;
        B.pb(mp(a,b));
    }
    sort(ALL(A),cmp);
    sort(ALL(B),cmp);
    // for (auto i : A)cout<<i.f<<' '<<i.s<<'\n';
    // for (auto i : B)cout<<i.f<<' '<<i.s<<'\n';
    curindA = N-1;
    curindB = M-1;
    curwgt = A.back().s + B.back().s;
    cursgf = A.back().f+B.back().f;
    ans = max(ans, cursgf);
    // cout<<curwgt<<' '<<cursgf<<'\n';
    if (curwgt > D){
        cout<<0;
        return 0;
    }
    while(curindA != 0 && curwgt + A[curindA-1].s <= D){
        --curindA;
        curwgt += A[curindA].s;
        cursgf += A[curindA].f;
    }
    while (curindA != N){
        while(curindB != 0 && curwgt + B[curindB-1].s <= D){
            --curindB;
            curwgt += B[curindB].s;
            cursgf += B[curindB].f;
        }
        ans = max(ans, cursgf);
        curwgt -= A[curindA].s;
        cursgf -= A[curindA].f;
        ++curindA;
    }
    cout<<ans;
}
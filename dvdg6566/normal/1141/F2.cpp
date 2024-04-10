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
ll FMOD = 1e9+6;
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (ll)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 1510

int A[MAXN];
int N,ans;
vector<pair<int,pi>> V;
vpi tmp,opt;

bool cmp(pi a, pi b){
    return a.s < b.s;
}

int main(){
    // freopen("in.txt","r",stdin);
    cin>>N;
    for (int i=1;i<=N;++i){
        cin>>A[i];
        A[i] += A[i-1];
    }
    for (int i=1;i<=N;++i){
        for (int j=i;j<=N;++j){
            int d = A[j] - A[i-1];
            V.pb(mp(d, mp(i,j)));
        }
    }
    sort(ALL(V));
    for (int i=0;i<SZ(V);++i){
        int cur = V[i].f;
        tmp.clear();
        tmp.pb(V[i].s);
        while (i+1 < SZ(V) && V[i+1].f == cur){
            ++i;
            tmp.pb(V[i].s);
        }
        sort(ALL(tmp), cmp);
        // for (auto i : tmp)cout<<i.f<<' '<<i.s<<' ';cout<<'\n';
        int curl = -1;
        int t = 0;
        for (int i=0;i<SZ(tmp);++i){
            pi c = tmp[i];
            if (c.f <= curl)continue;
            ++t;
            curl = c.s;
        }
        // cout<<t<<'\n';
        if (ans < t){
            ans = t;
            swap(tmp, opt);
        }
    }
    cout<<ans<<'\n';
    int curl = -1;
    int t = 0;
    for (int i=0;i<SZ(opt);++i){
        pi c = opt[i];
        if (c.f <= curl)continue;
        ++t;
        curl = c.s;
        cout<<c.f<<' '<<c.s<<'\n';
    }
}
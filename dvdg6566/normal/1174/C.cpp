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
ll MOD = 1e9+7;
#define lb lower_bound
#define ub upper_bound
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define MAXN 100100

bitset<MAXN> bs;
int out[MAXN];

int main(){
    bs.set();
    bs[0] = bs[1] = 0;
    int cnt = 1;
    for (int i=2;i*i<=MAXN;++i){
        if (bs[i] == 0)continue;
        out[i] = cnt;
        for (int j = i*i;j<=MAXN;j += i){
            bs[j] = 0;
            out[j] = cnt;
        }
        ++cnt;
    }
    for (int i=2;i<=MAXN;++i)if (bs[i] && out[i] == 0)out[i] = cnt++;
    int N;
    cin>>N;
    for (int i=2;i<=N;++i)cout<<out[i]<<' ';
}
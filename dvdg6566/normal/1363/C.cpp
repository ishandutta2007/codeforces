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
const ll MAXN=1010;
const ll MAXK=17;
const ll INF=1e18;
const ll MOD=998244353;

ll A[MAXN];
ll N,a,b,T,X;

int main(){
    cin>>T;
    while(T--){
        cin>>N>>X;
        for (int i=1;i<=N;++i)A[i]=0;
        for(int i=1;i<N;++i){
            cin>>a>>b;
            A[a]++;
            A[b]++;
        }
        if(A[X]<=1){
            cout<<"Ayush\n";
        }else{
            if(N%2==0)cout<<"Ayush\n";
            else cout<<"Ashish\n";
        }
    }
}
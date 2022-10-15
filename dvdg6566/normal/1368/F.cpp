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
const ll MAXN=200100;
const ll MOD=998244353;

int B[MAXN];
int A[MAXN];

pi fb(int n){
    pi bst=mp(1,0);
    for(int K=2;K<=n;++K){
        // blocks of K+1
        int space=(n+K-1)/(K);
        int blk=n-space-K+1;
        if(blk>bst.s)bst=mp(K,blk);
    }
    return bst;
}

int main(){

    // for(int i=1;i<=20;++i){
    //     cout<<i<<' '<<fb(i).s<<'\n';
    // }
    // return 0;

    int N;
    cin>>N;
    pi a=fb(N);
    int K=a.f;
    int ans=a.s;

    for(int i=1;i<N;++i){
        if(i%K)B[i]=1;
    }
    // for(int i=1;i<=N;++i)cout<<B[i]<<' ';
    int cur=0;
    while(cur<ans){
        vi tm;
        for(int i=0;i<N;++i)if(SZ(tm)<K){
            if(B[i]&&!A[i]){
                A[i]=1;
                ++cur;
                tm.pb(i);
            }
        }
        assert(SZ(tm)==K);
        cout<<K<<' ';
        for(auto i:tm)cout<<i<<' ';
        cout<<'\n'<<flush;


        int k;cin>>k;
        for(int i=0;i<K;++i){
            int a=i+k;
            if(a>N)a-=N;
            if(A[a]){
                A[a]=0;
                --cur;
            }
        }
    }

    cout<<0;
    return 0;
}
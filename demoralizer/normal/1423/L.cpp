#include "bits/stdc++.h"
using namespace std;
// #define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;



bitset<1003> sw[31];
const int sp=10;
bitset<1003> dog[1<<sp],cat[1<<(30-sp)];
void solve(){
    int n,s,d;
    cin>>n>>s>>d;
    for (int i = 0; i < s; ++i)
    {
        int c;
        cin>>c;
        for (int j = 0; j < c; ++j)
        {
            int x;
            cin>>x;
            x--;
            sw[i][x]=1;
        }
    }
    for (int i = 1; i < (1<<sp); ++i)
    {
        for (int j = 0; j < sp; ++j)
        {
            if(i&(1<<j)){
                dog[i]=dog[i^(1<<j)]^sw[j];
                break;
            }
        }
    }
    for (int i = 1; i < (1<<(30-sp)); ++i)
    {
        for (int j = 0; j < 30-sp; ++j)
        {
            if(i&(1<<j)){
                cat[i]=cat[i^(1<<j)]^sw[j+sp];
                break;
            }
        }
    }
    unordered_map<bitset<1003>,int> minlen;
    minlen[sw[30]]=0;
    for (int i = 0; i < (1<<(30-sp)); ++i)
    {
        if(minlen.count(cat[i]))
            amin(minlen[cat[i]],__builtin_popcountll(i));
        else minlen[cat[i]]=__builtin_popcountll(i);
    }
    // map<bitset<1003>,int> ml; 
    for (int i = 0; i < d; ++i)
    {
        bitset<1003> dogs=0;
        int t;
        cin>>t;
        for (int j = 0; j < t; ++j)
        {
            int k;
            cin>>k;
            dogs[k-1]=1;
        }
        int ans=100;
        for (int j = 0; j < (1<<sp); ++j)
        {
            if(minlen.count(dogs^dog[j])){
                ans=min(ans,minlen[dogs^dog[j]]+__builtin_popcountll(j));
            }
        }
        cout<<(ans==100?-1:ans)<<'\n';
    }
    return;
}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    #ifdef SIEVE
        sieve();
    #endif
    #ifdef NCR
        init();
    #endif
    int t=1;
    //cin>>t;
    while(t--) solve();
    return 0;
}
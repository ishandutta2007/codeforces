#include<bits/stdc++.h>
using namespace std ;

#define M 1000000007
#define MM 998244353 
#define ll long long 
#define pb push_back
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define memf(a) memset(a,false,sizeof(a))
#define all(v) v.begin(),v.end()
#define sz(a) (ll)a.size()
#define F first
#define S second
#define PI 3.1415926536
#define INF 2000000000000000000
#define endl "\n"
#define _time_ 1.0 * clock() / CLOCKS_PER_SEC
//RNG based on mersenne_twister 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll power(ll b,ll e,ll m)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b%m,e/2,m)%m;
    return power(b*b%m,e/2,m);
}
ll power( ll b, ll e)
{
    if(e==0) return 1;
    if(e&1) return b*power(b*b,e/2);
    return power(b*b,e/2);
}
template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

string c,s,t;
ll dp[1002][51][51],fuck[51][2],n,l1,l2;
void getfuck(string &s,int idx)
{
    size_t n=s.length();
    fuck[0][idx]=0;
    int curLen=0,i=1;
    for(;i<n;)
    {
        if(s[i]==s[curLen])
            fuck[i][idx]=++curLen,++i;
        else
        {
            if(curLen==0)
                fuck[i][idx]=0,++i;
            else
                curLen=fuck[curLen-1][idx];
        }
    }
    //for(i=0;i<n;++i)
    //    cout<<fuck[i][idx]<<" ";
    //cout<<'\n';

}
ll pre[26][60][2];
void preprocess(int idx)
{
    string x;
    if(idx==0)
        x=s;
    else x=t;
    int i,j;
    for(i=0;i<26;++i)
    {
        char ch='a'+i;
        int len=(idx==0)*l1+(idx==1)*l2;
        for(j=0;j<len;++j)
        {
            if(ch==x[j])
                pre[i][j][idx]=j+1;
            else if(j==0)
                pre[i][j][idx]=0;
            else
            {
                int zz=j;
                zz=fuck[zz-1][idx];
                pre[i][j][idx]=pre[i][zz][idx];
            }
        }
    }
}
int _runtimeTerror_()
{
    mem1(dp);
    cin>>c>>s>>t;
    n=sz(c);
    l1=sz(s);
    l2=sz(t);
    ll i,j,k,l;
    getfuck(s,0);
    getfuck(t,1);
    preprocess(0);
    preprocess(1);
    //cin>>c>>s>>t;
    for(i=0;i<=n;++i)
        for(j=0;j<=l1;++j)
            for(k=0;k<=l2;++k)
                dp[i][j][k]=-INF;
    dp[0][0][0]=0;
    for(i=1;i<=n;++i)
    {
        for(j=0;j<l1;++j)
        {
            for(k=0;k<l2;++k)
            {
                if(dp[i-1][j][k]==-INF)
                    continue;
                for(l=0;l<26;++l)
                {
                    char ch=l+'a';
                    if(c[i-1]==ch || c[i-1]=='*')
                    {
                        int cnt1=0,cnt2=0;
                        int xx=pre[l][j][0],yy=pre[l][k][1];
                        if(xx==l1)
                            xx=fuck[xx-1][0],++cnt1;
                        if(yy==l2)
                            yy=fuck[yy-1][1],++cnt2;
                        amax(dp[i][xx][yy],dp[i-1][j][k]+cnt1-cnt2);
                    }
                }
            }
        }
    }
    ll ans=-INF;
    for(j=0;j<l1;++j)
        for(k=0;k<l2;++k)
            amax(ans,dp[n][j][k]);
    cout<<ans<<endl;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    cerr<<"\n"<<_time_;
    return 0;
}
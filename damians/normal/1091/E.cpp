#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cout<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

ll d[1000001];
ll s[1000001];
ll larger[1000002];
ll smaller[1000002];
ll mlarger[1000002];
ll msmaller[1000002];
int n;


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n)cin>>d[i+1];
    sort(d+1,d+(n+1));
    reverse(d+1,d+(n+1));
    s[0]=0;
    REP(j,1,n) s[j]=s[j-1]+d[j];
    s[n+1]=s[n];
    s[n+2]=s[n];
    int indk=n+1;
    REP(k,1,n+1)
    {
        while(indk>0 && d[indk-1]<k) indk--;
        ll sum1=s[k]-s[0];
        ll sum2=0;
        int ind=max(k+1,indk);
        sum2=(ind-(k+1))*1LL*k+s[n]-s[ind-1];
        larger[k]=sum1-k*1LL*(k-1)-sum2;
        if (larger[k]>k) larger[k]=n+3;

        sum1=s[k-1]-s[0];
        ind=max(k,indk);
        sum2=(ind-k)*1LL*k+s[n]-s[ind-1];
        smaller[k]=sum2-sum1+k*1LL*(k-1);
        DBG(mp(larger[k],smaller[k]));
    }
    mlarger[0]=0;
    REP(k,1,n+1)mlarger[k]=max(mlarger[k-1],larger[k]);
    msmaller[n+2]=n+1;
    REPD(k,n+1,1)msmaller[k]=min(msmaller[k+1],smaller[k]);
    d[n+1]=0;
    d[0]=n+1;
    //DBG(s[n]);
    int i=n;
    int cnt=0;
    //DBG(vector<ll>(d+1,d+(n+1)));
    REP(g,0,n)
    {
        if ((s[n]+g)%2) continue;
        while(d[i]<=g) i--;
        ll la=mlarger[i];
        ll sm=msmaller[i+1];
        //DBG(i);
        //DBG(g);
        /*REP(k,1,n+1)
        {
            if (k<=i) la=max(la,larger[k]);
            else sm=min(sm,smaller[k]);
        }*/
        //DBG(la);
        //DBG(sm);
        if (la<=g && g<=sm) {cnt++;cout<<g<<" ";}
    }
    if (!cnt) cout<<"-1\n";

    return 0;
}
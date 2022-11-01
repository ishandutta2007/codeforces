#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <cstring>
#define REP(i,x,v)for(int i=x;i<=v;i++)
#define REPD(i,x,v)for(int i=x;i>=v;i--)
#define FOR(i,v)for(int i=0;i<v;i++)
#define FORE(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REMIN(x,y) (x)=min((x),(y))
#define REMAX(x,y) (x)=max((x),(y))
#define pb push_back
#define sz size()
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define un(v) v.erase(unique(ALL(v)),v.end())
#define LOLDBG1
#ifdef LOLDBG
#define DBG(vari) cerr<<#vari<<" = "<<vari<<endl;
#define DBG2(v1,v2) cerr<<(v1)<<" - "<<(v2)<<endl;
#else
#define DBG(vari)
#define DBG2(v1,v2)
#endif
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define CZ3(x,y,z) scanf("%d%d%d",&(x),&(y),&(z));
#define ALL(x) (x).begin(),(x).end()
#define tests int dsdsf;cin>>dsdsf;while(dsdsf--)
#define testss int dsdsf;CZ(dsdsf);while(dsdsf--)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }


#define X 29
#define ull unsigned long long
#define MAXN 1000003

char s[MAXN];
char t[MAXN];
int n;
ull hasze[MAXN];
ull haszet[MAXN];
ull haszer[MAXN];
ull pX[MAXN];

inline ull h(int a, int b)//[a..b)
{
    return hasze[a]-pX[b-a]*hasze[b];
}

inline ull hr(int a, int b)//[a..b)
{
    return haszer[a]-pX[b-a]*haszer[b];
}

inline ull ht(int a, int b)//[a..b)
{
    return haszet[a]-pX[b-a]*haszet[b];
}


int mxtyl[MAXN];
int prefmx[MAXN];

int main()
{
    pX[0]=1;REP(i,1,MAXN-1) pX[i]=X*pX[i-1];
    gets(s);
    n=strlen(s);
    hasze[n]=0;
    REPD(i,n-1,0) hasze[i]=hasze[i+1]*X+s[i];
    haszer[n]=0;
    REPD(i,n-1,0) haszer[i]=haszer[i+1]+s[i]*pX[n-1-i];
    gets(t);
    int m=strlen(t);
    if (m!=n)
    {
        cout<<"-1 -1\n";
        return 0;
    }
    haszet[n]=0;
    REPD(i,n-1,0) haszet[i]=haszet[i+1]*X+t[i];
    DBG(n);
    FOR(i,n)
    {
        int lo=0,hi=n,mid;
        while(hi-lo>1)
        {
            mid=(lo+hi)/2;
            if (haszer[n-mid]==ht(i,i+mid)) lo=mid;
            else hi=mid;
        }
        mxtyl[i]=lo+i;
        DBG(i);
        DBG(mxtyl[i]);
    }
    prefmx[0]=-1;
    REP(i,1,n) prefmx[i]=max(prefmx[i-1],mxtyl[i-1]);
    int i0=0;
    while(i0<n-1 && t[n-1-i0]==s[i0]) i0++;
    i0--;
    REPD(i,i0,0)
    {
        int lo=i+1,hi=n,mid;
        while(hi-lo>1)
        {
            mid=(lo+hi)/2;
            if (h(i+1,mid)==ht(0,mid-i-1)) lo=mid;
            else hi=mid;
        }
        
        int dl=lo-i-1;
        DBG(dl);
        int mx=0;
        //FOR(j,dl+1) REMAX(mx,mxtyl[j]);
        mx=prefmx[dl+1];
        DBG(mx+i);
        if (mx+i+1>=n)
        {
            REP(j,i+1,n)
            {
                DBG(string(t).substr(j-1-i,n-i-1-(j-1-i)));
                DBG(ht(j-1-i,n-i-1));

                DBG(j);
                if (haszer[j]==ht(j-1-i,n-i-1))
                {
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        DBG(mx);
    }
    cout<<"-1 -1\n";
    
    
    

    return 0;
}
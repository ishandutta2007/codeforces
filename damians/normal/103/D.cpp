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

int w[300001];
ll pref[400050];
int pos[5000];

int n;



int x[300004],y[300004];
vi q[101];
ll ans[300004];


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    FOR(i,n) cin>>w[i];
    int p;cin>>p;
    FOR(i,p)
    {
        int a,b;
        cin>>x[i]>>y[i];
        x[i]--;
        a=x[i];
        b=y[i];
        if (y[i]>100)
        {
            int ind=a;
            ll wyn=0;
            while(ind<n) {wyn+=w[ind];ind+=b;}
            ans[i]=wyn;
            continue;
        }
        q[y[i]].pb(i);
        DBG(a);
        DBG(b);
        
    }
    REP(i,1,100)
    {
        //if (q[i].sz==0) continue;
        int last=0;
        FOR(j,i)
        {
            pos[j]=last;
            pref[last++]=0;
            int ind=j;
            while(ind<n)
            {
                pref[last]=pref[last-1]+w[ind];
                ind+=i;
                last++;
            }
        }
        DBG(last);
        FORE(j,q[i])
        {
            int a=x[*j],b=y[*j];
            int m=a%b;
            int mx=(n-m+b-1)/b;
            ans[*j]=pref[pos[m]+mx]-pref[pos[m]+a/b];
        }
    }
    FOR(i,p) cout<<ans[i]<<"\n";
    
    

    return 0;
}
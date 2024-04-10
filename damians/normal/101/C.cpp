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
#define LOLDBG
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
#include <complex>
typedef complex<ll> zesp;


bool div(zesp q, zesp p)
{
    q*=zesp(p.real(),-p.imag());
    ll pm=p.real()*p.real()+p.imag()*p.imag();
    return (q.real()%pm==0 && q.imag()%pm==0);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    ll a1,a2,b1,b2,c1,c2;
    
    cin>>a1>>a2>>b1>>b2>>c1>>c2;
    zesp C(c1,c2),A(a1,a2),B(b1,b2);
    zesp i(0,1);
    if (C==zesp(0,0))
    {
        FOR(j,9)
        {
            A*=i;
            if (A==B)
            {
                cout<<"YES";
                return 0;
            }
        }
        cout<<"NO";
        return 0;
        
    }
    FOR(j,9)
    {
        A*=i;
            if (div(B-A,C))
            {
                cout<<"YES";
                return 0;
            }
    }
    cout<<"NO";
    

    return 0;
}
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
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

vector<int> inters(vector<int> a, vector<int> b)
{
    vi w(201,0);
    FOR(i,201) w[i]=a[i]*b[i];
    return w;
}

vector<int> sety[200*200];
vi wyn[300];
set<int> liczby;

int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    FOR(i,n*(n-1)/2)
    {
        int d,a;
        cin>>d;
        sety[i]=vi(201,0);
        FOR(j,d)
        {
            cin>>a;
            sety[i][a]=1;
            liczby.insert(a);
        }
    }
    int k=0;
    if (n==2)
    {
        int d=0;
        vi v;
        FOR(i,201) if (sety[0][i]) v.pb(i);
        cout<<"1 "<<v[0]<<endl;
        cout<<v.sz-1<<" ";
        REP(i,1,v.sz-1) cout<<v[i]<<" ";
        cout<<endl;
        return 0;
    }
    while(k<n)
    {
        vi v(201,1);
        int l=*(liczby.begin());
        FOR(i,n*(n-1)/2)
        {
            if (sety[i][l])
            {
                v=inters(v,sety[i]);
            }
        }
        wyn[k++]=v;
        FOR(i,201) if (v[i]) liczby.erase(i);
    }
    FOR(i,n)
    {
        int d=0;
        FOR(j,201) d+=wyn[i][j];
        cout<<d<<" ";
        FOR(j,201) if (wyn[i][j]) cout<<j<<" ";
        cout<<endl;
    }

    return 0;
}
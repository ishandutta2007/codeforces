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

#define MOD 1000000007
#define R 4 //rozmiar macierzy

struct mat
{
    int t[R][R];
    mat(bool typ)//0 lub 1
    {
        FOR(i,R) FOR(j,R) t[i][j]=typ&(i==j);   
    }
};



mat operator*(const mat &m1, const mat &m2)
{
    mat w(0);
    FOR(i,R) FOR(j,R)
    {
        ll ts=0;
        FOR(k,R) ts+=((ll)m1.t[i][k]*m2.t[k][j])%MOD;
        w.t[i][j]=ts%MOD;
    }
    return w;
}

mat operator+(const mat &m1, const mat &m2)
{
    mat w(0);
    FOR(i,R) FOR(j,R)
        w=(m1.t[i][j]+m2.t[i][j])%MOD;
    return w;
}

mat podnies(mat m, ll k)
{
    mat m0(1);
    while(k)
    {
        if (k%2)
            m0=m0*m;
        k/=2;
        if (k) m=m*m;
    }
    return m0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    mat m(0);
    FOR(i,4) FOR(j,4)
    {
        if (i!=j) m.t[i][j]=1;
    }
    int n;CZ(n);
    m=podnies(m,n);
    cout<<m.t[0][0];

    return 0;
}
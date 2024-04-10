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
#define FOR(i,v)REP(i,0,(int)(v)-1)
#define FORD(i,v)REPD(i,(int)(v)-1,0)
#define pb push_back
#define sz size
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define IN(x,y) ((y).find((x))!=(y).end())
#define DBG(vari) cout<<#vari<<" = "<<vari<<endl;
#define CZ(x) scanf("%d",&(x));
#define CZ2(x,y) scanf("%d%d",&(x),&(y));
#define ALL(x) (x).begin(),(x).end()

using namespace std;

#define MOD 1000000007
#define R 2 //rozmiar macierzy

struct mat
{
    int t[R][R];
    mat(bool typ)//0 lub 1
    {
		FOR(i,R) FOR(j,R) t[i][j]=typ&(i==j);	
	}
};

void wypisz(mat m1)
{
    FOR(i,R)
    {   
        FOR(j,R) cout<<m1.t[i][j]<<" ";
        cout<<endl;
    }
}

mat operator*(const mat &m1, const mat &m2)
{
    mat w(0);
    FOR(i,R) FOR(j,R)
    {
        ll ts=0;
        FOR(k,R) ts+=((ll)m1.t[i][k]*m2.t[k][j])%MOD;//tuaj mozna zoptymalizowac robiac modulo rzadziej, zeby sie tylko miescilo w ll
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

vector<int> naloz(const mat &m,vector<int> vec)
{
    vector<int> wyn(R,0);
    FOR(i,R) FOR(j,R)
    {
        wyn[i]+=(((ll)vec[j])*m.t[i][j])%MOD;
        if (wyn[i]>=MOD) wyn[i]-=MOD;
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);
    mat m(0);
    m.t[0][0]=m.t[1][1]=3;
    m.t[0][1]=m.t[1][0]=1;
    ll n;cin>>n;
    m=podnies(m,n);
    cout<<m.t[0][0];
    return 0;
}
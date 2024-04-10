#pragma comment(linker, "/STACK:64000000")
#define  _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

#define REP(i,n) for (int i = 0, _##i = (n); i < _##i; ++i)
#define REPD(i,n) for (int i = (n)-1; i >= 0; --i)
#define FOR(i,a,b) for (int i = (a), _##i = (b); i <= _##i; ++i)
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define CLEAR(x) memset(x,0,sizeof x)
#define FILL(x,v) memset(x,v,sizeof x)
#define ALL(x) (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define pb push_back
#define MP make_pair
const double pi = acos(-1.0);
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef long long LL;

#define INF 1000000000

#define N 1024000
int n,a[N];
PII ord[N];
set<PII> seg;

/*int num_1[N];
LL sum_1[N];
void add_lin_1(int x, int y, int h, LL mult) {
	FOR(i,x,y)
	{
		num_1[i] += mult*(LL)i;
		sum_1[i] += mult*h*(LL)i;
	}
}
void add_cnst_1(int x, int y, int h, LL mult) {
	FOR(i,x,y)
	{
		num_1[i] += mult;
		sum_1[i] += mult*h;
	}
}*/


LL sum[N];
LL c_diff[N],l_diff[N];

void add_lin(int x, int y, int h, LL mult) {
	//add_lin_1(x,y,h,mult);
	if (x>y) return;

	l_diff[x] += h*mult;
	l_diff[y+1] -= h*mult;
}

void add_cnst(int x, int y, int h, LL mult) {
	//add_cnst_1(x,y,h,mult);
	if (x>y) return;

	c_diff[x] += h*mult;
	c_diff[y+1] -= h*mult;
}

/*void stupid()
{
	FOR(k,1,n)
	{
		LL r = 0;
		REP(i,n-k+1)
		{
			int h = a[i];
			REP(j,k)
				h=min(h,a[i+j]);
			r+=h;
		}
		if (r!=sum[k])
			printf("hmmm %d %I64d %I64d\n",k,sum[k],r);
	}
}*/

int main()
{
	//freopen("d.in","r",stdin);

	scanf("%d",&n); REP(i,n) scanf("%d",a+i);
	/*n=1000000;
	REP(i,n)
		//a[i] = (((LL)rand())<<30)%1000000000;
		a[i]=rand();
		//a[i] = 5;/**/

	REP(i,n) ord[i] = PII(a[i],i);
	sort(ord,ord+n);
	seg.insert(PII(0,n-1));
	CLEAR(sum);
	CLEAR(c_diff);
	CLEAR(l_diff);
	REP(ii,n)
	{
		int i = ord[ii].second;
		set<PII>::iterator it = seg.lower_bound(PII(i,INF));
		--it;
		int x = it->first;
		int y = it->second;
		seg.erase(it);
		if (x<=i-1) seg.insert(PII(x,i-1));
		if (i+1<=y) seg.insert(PII(i+1,y));
		int dx = i-x+1;
		int dy = y-i+1;
		// 1
		add_lin(1,min(dx,dy),a[i],1);
		// 2
		add_cnst(min(dx,dy)+1,max(dx,dy),a[i],min(dx,dy));
		// 3
		add_lin(max(dx,dy)+1,dx+dy-1,a[i],-1);
		add_cnst(max(dx,dy)+1,dx+dy-1,a[i],dx+dy);
	}

	LL cc=0,ll=0;
	FOR(k,1,n)
	{
		cc += c_diff[k];
		ll += l_diff[k];
		sum[k] = cc+ll*k;
	}

	/*
	FOR(i,1,n)
	{
		if (num_1[i] != n-i+1)
			printf("BAD %d %d\n",i,num_1[i]);
		if (sum_1[i] != sum[i])
			printf("OOPS %d %I64d %I64d\n",i,sum[i],sum_1[i]);
	}
	/**/

	//stupid();
	//printf("!!!\n");
	
	int m;
	scanf("%d",&m);
	REP(i,m)
	{
		int k;
		scanf("%d",&k);
		printf("%.12lf\n",sum[k]/(1.0*(n-k+1)));
	}
	return 0;
}
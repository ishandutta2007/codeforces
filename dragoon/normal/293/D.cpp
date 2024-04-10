#pragma warning(disable:4786)
#include<iostream>
#include<assert.h>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X)>0?(X):(-(X)))
#define S(X) ((X)*(X))
#define SZ(V) (int)V.size()

//typedef int LL;
typedef __int64 LL;

typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<double, double> PDD;


int n;
vector<PLL> V;

int turn_ccw(PLL A, PLL B, PLL C)
{
	LL d = A.first * B.second + B.first * C.second + C.first * A.second;
	d -=   B.first * A.second + C.first * B.second + A.first * C.second;

	return d > 0;
}

int LINE(PLL A, PLL B, PLL C)
{
	LL d = A.first * B.second + B.first * C.second + C.first * A.second;
	d -=   B.first * A.second + C.first * B.second + A.first * C.second;

	return d == 0;
}

void reverse()
{
	int i, j;

	for(i = 0; i < n; i++)
		if( !LINE(V[i], V[(i+1)%n], V[(i+2)%n]) )
			break;

	if( turn_ccw(V[i], V[(i+1)%n], V[(i+2)%n]) )
	{
		for(i = 0, j = n - 1; i < j; i++, j--)
			swap(V[i], V[j]);
	}
}

void rotate()
{
	int id = n - 1;
	int i;

	for(i = 0; i < n; i++)
	{
		if(V[i].first > V[id].first)
			id = i;
	}

	while( V[(id + n - 1)%n].first == V[id].first)
		id = (id + n - 1) % n;

	vector<PLL> VV;
	for(i = 0; i < n; i++)
		VV.push_back( V[ (i + id)%n ] );

	V = VV;
}

void mirror()
{
	int i;
	PLL X;

	for(i = 0; i < n; i++)
	{
		X = V[i];
		V[i].first = X.second;
		V[i].second = X.first;
	}
}

LL FLOOR(LL A, LL B)
{
	if( A >= 0 )
		return A/B;
	return (A - (B-1))/B;
}

LL CEIL(LL A, LL B)
{
	if(A >= 0)
		return (A + B - 1)/B;
	return -((-A)/B);
}


LL find_uy(PLL A, PLL B, LL x)
{
	return FLOOR(((A.second - B.second)*(x - A.first)),(A.first - B.first)) + A.second;
}

LL find_ly(PLL A, PLL B, LL x)
{
	return CEIL( (A.second - B.second)*(x - A.first),(A.first - B.first)) + A.second;
}

LL N;
PDD Find()
{
	LL i;
	double first, second;
	LL uy, ly;
	int a, b;
	LL maxx, minx;
	LL cnt;

	maxx = -10000000;
	minx =  10000000;
	
	for(i = 0; i < n; i++)
	{
		maxx = MAX(maxx, V[i].first);
		minx = MIN(minx, V[i].first);
	}

	a = 0;
	b = 0;
	if(V[1].first==V[0].first) b = 1;
	
	first = second = 0;
	for(i = maxx; i >= minx; i--)
	{
		while( i < V[(a+n-1)%n].first )
		{
			a = (a+n-1)%n;
		}

		while( i < V[(b+1)%n].first )
		{
			b = (b+1)%n;
		}

		uy = find_uy(V[a], V[(a+n-1)%n], i);
		ly = find_ly(V[b], V[(b+1)%n], i);

		cnt = uy - ly + 1;
		N += cnt;
		first += 1.*i*i*1.*cnt;
		second += 1.*i*cnt;
	}

	return PDD(first, second);
}

int main()
{
	int i;
	LL x, y;
	PDD X, Y;
	double ans, NN;

	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%I64d%I64d", &x, &y);
		V.push_back( PLL(x, y) );
	}

	reverse();
	for(i = 0; i < n; i++)
		if(turn_ccw(V[i], V[(i+1)%n], V[(i+2)%n]))
			assert(0);

	rotate();

	N = 0;
	X = Find();

	mirror();
	reverse();
	rotate();
	N = 0;
	Y = Find();

	NN = N*1.;
	ans  = NN*X.first - (X.second*X.second);
	ans += NN*Y.first - (Y.second*Y.second);
	ans /= ((NN-1)*(NN));

	printf("%.10lf\n", ans);


//	printf("%I64d\n", N);
//	printf("%lf %lf\n", X.first, X.second);
//	printf("%lf %lf\n", Y.first, Y.second);

	
	return 0;
}
#pragma warning(disable:4786)
#include<iostream>
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
#include<math.h>
#include<stack>
using namespace std;

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(X) ((X)>0?(X):(-(X)))
#define S(X) ((X)*(X))
#define D(x1,y1,x2,y2) (sqrt( S((x1)-(x2)) + S((y1)-(y2)) ))
#define EPS 1e-8
#define eps 1e-8
#define IN(a,b,c) if(a>=b && a<=c)
#define CLEAR(a) memset(a,0,sizeof(a))
#define in(a,b,c) (a>=b && a<=c)
#define SORT(A) sort(A.begin(),A.end())
#define SZ(X) (int)(X.size())
#define D2(x1,y1,x2,y2) ( S((x1)-(x2)) + S((y1)-(y2)) )

typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef __int64 LL;

//int dr[]={0,0,1,-1,-1,-1,1,1};
//int dc[]={1,-1,0,0,1,-1,1,-1};

struct Triangle
{
	double x1, x2,y1,y2,x3,y3;
}T[305];

struct Segment
{
	double x1, x2,y1,y2;
	int id;
	Segment(double a, double b, double c, double d, int e)
	{
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
		id = e;
	}

	Segment(){}
}segment[350];

double glbl_t;
int n;
PDD V[90000];
int sz, SZ;

int CUT(int i, int j, int k)
{
	double x1,y1,dx1,dy1;
	double x2,y2,dx2,dy2;
	double A,B,C,T1,T2;

	x1 = segment[i].x1; y1 = segment[i].y1;
	dx1 = segment[i].x2 - segment[i].x1;
	dy1 = segment[i].y2 - segment[i].y1;

	x2 = segment[j].x1; y2 = segment[j].y1;
	dx2 = segment[j].x2 - segment[j].x1;
	dy2 = segment[j].y2 - segment[j].y1;

	A = -dx2*(y1-y2) + dy2*(x1-x2);
	B = dy1*(x1-x2) - dx1*(y1-y2);
	C = -dx1*dy2 + dx2*dy1;

	if(fabs(C)<1e-6) return 0;

	T1 = A/C;
	T2 = B/C;

	if(T2 < -eps || T2 > 1+eps) return 0;
	if(V[k].first-eps>T1 || T1>V[k].second+eps) return 0;

	glbl_t = T1;
	
	return 1;
}

double AREA(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double d = x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1;
	if(d<0) d = -d;
	return d;
}

int inside(int id, double x, double y)
{
	int i;
	double area;

	for(i=0;i<n;i++) if(i!=id)
	{
		area = AREA(T[i].x1,T[i].y1,T[i].x2,T[i].y2, T[i].x3,T[i].y3) -
			   AREA(T[i].x1,T[i].y1,T[i].x2,T[i].y2, x,y) -
			   AREA(T[i].x1,T[i].y1,x,y, T[i].x3,T[i].y3) -
			   AREA(x,y,T[i].x2,T[i].y2, T[i].x3,T[i].y3);

		if(fabs(area)<1e-5)
			return 0;
	}

	return 1;
}

int main()
{
	int i;
	double ans,t,x,y,x1,y1,x2,y2;

	scanf("%d",&n);
	
	if(n==0)
	{
		printf("%.10lf\n",0.0);
		return 0;
	}

	sz = 0;
	for(i=0;i<n;i++)
	{
		scanf("%lf%lf%lf%lf%lf%lf",&T[i].x1,&T[i].y1,&T[i].x2,&T[i].y2,&T[i].x3,&T[i].y3);
		segment[sz++] = Segment( T[i].x1, T[i].y1, T[i].x2, T[i].y2, i );
		segment[sz++] = Segment( T[i].x2, T[i].y2, T[i].x3, T[i].y3, i );
		segment[sz++] = Segment( T[i].x3, T[i].y3, T[i].x1, T[i].y1, i );
	}

	int j,k;

	ans = 0;
	for(i=0;i<sz;i++)
	{
		V[0] = PDD(0,1);
		SZ = 1;
		for(j=0;j<sz;j++) if(segment[i].id != segment[j].id)
		{
			for(k=0;k<SZ;k++)
				if( CUT(i, j, k) )
				{
					//glbl_t;
					V[SZ].first = glbl_t;
					V[SZ++].second = V[k].second;
					V[k].second = glbl_t;
					break;
				}
		}

		for(j=0;j<SZ;j++)
		{
			t = (V[j].first+V[j].second)/2.;
			x = segment[i].x1 + t*(segment[i].x2 - segment[i].x1);
			y = segment[i].y1 + t*(segment[i].y2 - segment[i].y1);

			if(inside(segment[i].id,x,y))
			{
				x1 = segment[i].x1 + V[j].first*(segment[i].x2 - segment[i].x1);
				y1 = segment[i].y1 + V[j].first*(segment[i].y2 - segment[i].y1);
				x2 = segment[i].x1 + V[j].second*(segment[i].x2 - segment[i].x1);
				y2 = segment[i].y1 + V[j].second*(segment[i].y2 - segment[i].y1);
				ans += D(x1,y1,x2,y2);
			}
		}
	}

	printf("%.10lf\n",ans);

	return 0;
}
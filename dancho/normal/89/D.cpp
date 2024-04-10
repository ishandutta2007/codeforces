#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const double eps = 1e-7;

struct point
{
	double x, y, z;
	point operator+( point b )
	{
		point r;
		r.x = x + b.x; r.y = y + b.y; r.z = z + b.z;
		return r;
	}
};

point mp( double x, double y, double z )
{
	point r; r.x = x; r.y = y; r.z = z;
	return r;
}

point NO = mp( 1e11, 1e11, 1e11 );

double dist( point p, point q )
{
	return sqrt( (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y) + (p.z-q.z)*(p.z-q.z) );
}

double crCirLine( point O, double r, point st, point d )
{
	double a, b, c, D;
	a = d.x*d.x + d.y*d.y + d.z*d.z;
	b = 2.0*( d.x*(st.x-O.x)+d.y*(st.y-O.y)+d.z*(st.z-O.z) );
	c = O.x*O.x + O.y*O.y + O.z*O.z + st.x*st.x + st.y*st.y + st.z*st.z - 2.0*( O.x*st.x+O.y*st.y+O.z*st.z ) - r*r;
	D = b*b - 4*a*c;
	if ( D < 0.0 ) return 1e20;
	double t1, t2;
	D = sqrt( D );
	t1 = (-b-D)/(2.0*a);
	t2 = (-b+D)/(2.0*a);
	point r1, r2;
	r1 = NO; r2 = NO;
//	cout << t1 << " " << t2 << endl;
	//cout << dist( O, st ) << " " << r << endl;
	//printf( "%.20lf\n", t2 );
	if ( ( t1 <= 0 ) && ( t2 <= 0 ) )
		return 1e20;
	if ( t1 <= 0 ) return t2;
	if ( t2 <= 0 ) return t1;
	
	return min( t1, t2 );
}

int n;
point A, v;
double R;
point mo[128];
double r[128];
int m[128];
point sp[128][12];

int main()
{
	int i, j;
	double be = 1e20;
	double V;
	
	scanf( "%lf %lf %lf %lf %lf %lf %lf", &A.x, &A.y, &A.z, &v.x, &v.y, &v.z, &R );
	V = sqrt( v.x*v.x + v.y*v.y + v.z*v.z );
	//cout << V << endl;
	scanf( "%d", &n );
	for ( i = 1; i <= n; i++ )
	{
		scanf( "%lf %lf %lf %lf %d", &mo[i].x, &mo[i].y, &mo[i].z, &r[i], &m[i] );
		for ( j = 1; j <= m[i]; j++ )
		{
			scanf( "%lf %lf %lf", &sp[i][j].x, &sp[i][j].y, &sp[i][j].z );
			be = min( be, crCirLine( mo[i]+sp[i][j], R, A, v ) );
//			cout << i << " " << j << " " << crCirLine( mo[i]+sp[i][j], R, A, v ) << endl;
		}
		be = min( be, crCirLine( mo[i], R+r[i], A, v ) );
//		cout << i << " " << crCirLine( mo[i], R+r[i], A, v ) << endl;
	}
	if ( be < 1e10 )
		printf( "%.10lf\n", be );
	else
		printf( "-1\n" );
	return 0;
}
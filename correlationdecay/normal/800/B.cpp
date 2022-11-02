#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#define maxn 100009
using namespace std;
const double eps=1e-6;
const double PI=acos(-1.0);
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	void read()
	{
		scanf("%lf%lf",&x,&y);
		return;
	}
	void print()
	{
		printf("%.6f %.6f",x,y);
	}
};
typedef Point Vector;

Vector operator + (Vector A,Vector B){return Vector(A.x+B.x,A.y+B.y);}
Vector operator - (Point A,Point B){return Vector(A.x-B.x,A.y-B.y);}
Vector operator * (Vector A,double p){return Vector(A.x*p,A.y*p);}
Vector operator / (Vector A,double p){return Vector(A.x/p,A.y/p);}

int sgn(double x)
{
	if(x>-eps&&x<eps)
		return 0;
	else if(x>eps)
		return 1;
	else
		return -1;
}
bool operator <(const Point& a,const Point& b)
{
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}
bool operator ==(const Point& a,const Point& b)
{
	return sgn(a.x-b.x)==0&&sgn(a.y-b.y)==0;
}

double Dot(Vector A,Vector B){return A.x*B.x+A.y*B.y;}
double Length(Vector A){return sqrt(Dot(A,A));}
double Angle(Vector A,Vector B){return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector A,Vector B){return A.x*B.y-A.y*B.x;}
double Area2(Point A,Point B,Point C){return Cross(B-A,C-A);}
double angle(Vector v){return atan2(v.y,v.x);}

Vector Rotate(Vector A,double rad)
{
	return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad));
}
Vector Normal(Vector A)
{
	double L=Length(A);
	return Vector(-A.y/L,A.x/L);
}

Point GetLineIntersection(Point P,Vector v,Point Q,Vector w)
{
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;
}
double DistanceToLine(Point P,Point A,Point B)
{
	Vector v1=B-A,v2=P-A;
	return fabs(Cross(v1,v2))/Length(v1);
}
double DistanceToSegment(Point P,Point A,Point B)
{
	if(A==B)return Length(P-A);
	Vector v1=B-A,v2=P-A,v3=P-B;
	if(sgn(Dot(v1,v2))<0) 
		return Length(v2);
	else if(sgn(Dot(v1,v3))>0)
		return Length(v3);
	else
		return fabs(Cross(v1,v2))/Length(v1);
}
Point GetLineProjection(Point P,Point A,Point B)
{
	Vector v=B-A;
	return A+v*(Dot(v,P-A)/Dot(v,v));
}
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2)
{
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1),
		   c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return sgn(c1)*sgn(c2)<0&&sgn(c3)*sgn(c4)<0;
}
bool OnSegment(Point p,Point a1,Point a2) // p is on segment a1,a2 strictly.
{
	return sgn(Cross(a1-p,a2-p))==0&&sgn(Dot(a1-p,a2-p))<0;
}

struct Circle
{
	Point c;
	double r;
	Circle(Point c,double r):c(c),r(r){}
	Circle(){}
	Point point(double a)
	{
		return Point(c.x+cos(a)*r,c.y+sin(a)*r);
	}
	void read()
	{
		double x,y;
		scanf("%lf%lf%lf",&x,&y,&r);
		c=Point(x,y);
	}
};
struct Line
{
	Point p;
	Vector v;
	Line(Point p,Vector v):p(p),v(v){}
	Point point(double t)
	{
		return p+v*t;
	}
};
int getLineCircleIntersection(Line L,Circle C,double &t1,double &t2,vector<Point>& sol)
{
	double a=L.v.x,b=L.p.x-C.c.x,c=L.v.y,d=L.p.y-C.c.y;
	double e=a*a+c*c,f=2*(a*b+c*d),g=b*b+d*d-C.r*C.r;
	double delta=f*f-4*e*g;
	if(sgn(delta)<0) return 0;  //
	if(sgn(delta)==0)       //
	{
		t1=t2=-f/(2*e);
		sol.push_back(L.point(t1));
		return 1;
	}
	t1=(-f-sqrt(delta))/(2*e);
	sol.push_back(L.point(t1));
	t2=(-f+sqrt(delta))/(2*e);
	sol.push_back(L.point(t2));
	return 2;
}

int getCircleCircleIntersection(Circle C1,Circle C2,vector<Point>&sol)
{
	double d=Length(C1.c-C2.c);
	if(sgn(d)==0)
	{
		if(sgn(C1.r-C2.r)==0) return -1;     //
		return 0;                            //
	}
	if(sgn(C1.r+C2.r-d)<0) return 0;         //
	if(sgn(fabs(C1.r-C2.r)-d)>0) return 0;   //

	double a=angle(C2.c-C1.c);          //
	double da=acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));  
	Point p1=C1.point(a-da),p2=C1.point(a+da);

	sol.push_back(p1);
	if(sgn(C1.r+C2.r-d)==0) return 1;            //

	sol.push_back(p2);
	return 2;
}

int getTangents(Point p,Circle C,vector<Vector>&v)
{
	Vector u=C.c-p;
	double dist=Length(u);
	if(dist<C.r)                    //
		return 0;
	else if(sgn(dist-C.r)==0)       //
	{
		v.push_back(Rotate(u,PI/2));
		return 1;
	}	
	else
	{
		double ang=asin(C.r/dist);
		v.push_back(Rotate(u,ang));
		v.push_back(Rotate(u,-ang));
		return 2;
	}
}
Point fst[10],scd[10];
int getTangents(Circle A,Circle B,Point *a,Point *b)
{
	int cnt=0;
	if(A.r<B.r)
	{
		swap(A,B);swap(a,b);
	}
	double d=Length(A.c-B.c);
	double rdiff=A.r-B.r;
	double rsum=A.r+B.r;
	if(sgn(d-rdiff)<0)
		return 0;

	double base=angle(B.c-A.c);
	if(sgn(d)==0&&sgn(rdiff)==0)
		return -1;
	if(sgn(d-rdiff)==0)
	{
		a[cnt]=A.point(base);b[cnt]=B.point(base);cnt++;
		return 1;
	}
	double ang=acos((A.r-B.r)/d);
	a[cnt]=A.point(base+ang);b[cnt]=B.point(base+ang);cnt++;
	a[cnt]=A.point(base-ang);b[cnt]=B.point(base-ang);cnt++;

	if(sgn(d-rsum)==0)
	{
		a[cnt]=A.point(base);b[cnt]=B.point(base+PI);cnt++;
	}
	else if(sgn(d-rsum)>0)
	{
		double ang=acos((A.r+B.r)/d);
		a[cnt]=A.point(base+ang);b[cnt]=B.point(base+ang+PI);cnt++;
		a[cnt]=A.point(base-ang);b[cnt]=B.point(base-ang+PI);cnt++;
	}
	return cnt;
}

Point p[maxn];
int n;


bool check(double r){
	Point A[10], B[10];
	p[n] = p[0];
	for(int i = 0 ; i < n; i++){
		int cnt = getTangents(Circle(p[i], r), Circle(p[i + 1], r), A, B);
		for(int k = 0; k < cnt; k++){
			Vector cur = B[k] - A[k];
			for(int j = 0; j < n; j++){
				if(j == i)
					continue;
				if(j == (i + 1) % n)
					continue;
				Vector Px = p[j] - A[k];
				if(Cross(Px, cur) < 1e-9)
					return 0;
				if(DistanceToLine(p[j], A[k], B[k]) < r)
					return 0;
			}
		}
	}
	return 1;
}

void solve(){
	double mi = 1e18;
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			mi = min(mi, Length(p[i] - p[j]));
		}
	}
	double L = 0, R = mi / 2;
	//cout << check(0.1) << endl;
	
	for(int i = 0 ; i < 40; i++){
		double M = (L + R) / 2;
		if(check(M))
		 	 L = M;
		else
			R = M;
	}
	
	printf("%.10f\n", L);
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		p[i].read();
	}
	solve();
	return 0;
}
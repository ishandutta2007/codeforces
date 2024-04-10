//int!
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define all(a) a.begin(), a.end()
inline int ckmax(int &a, int b) { return a < b ? a = b, 1 : 0; }
inline int ckmin(int &a, int b) { return a > b ? a = b, 1 : 0; }

const int maxn = 100100;

struct Point{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y) { }
};

typedef Point Vector;

Vector operator + (Vector A,Vector B) { return Vector(A.x+B.x,A.y+B.y); }
Vector operator - (Point A,Point B) { return Vector(A.x-B.x,A.y-B.y); }
Vector operator * (Vector A,double p) { return Vector(A.x*p,A.y*p); }
Vector operator / (Vector A,double p) { return Vector(A.x/p,A.y/p); }

bool operator < (const Point &a,const Point &b){
	return a.x==b.x?a.y<b.y:a.x<b.x;
}

const double eps = 1e-11;

int dcmp(double x){
	if (fabs(x)<eps) return 0; else return x<0?-1:1;
}

bool operator == (const Point &a,const Point &b){
	return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0;
}

double Dot(Vector A,Vector B) { return A.x*B.x+A.y*B.y; }
double Length(Vector A) { return sqrt(Dot(A,A)); }
double Angle(Vector A,Vector B) { return acos(Dot(A,B)/Length(A)/Length(B)); }

double Cross(Vector A,Vector B) { return A.x*B.y-A.y*B.x; }
double Area2(Point A,Point B,Point C) { return Cross(B-A,C-A); }

Vector Rotate(Vector A,double rad){
	return Vector(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)-A.y*cos(rad));
}

Vector Normal(Vector A){
	double L=Length(A);
	return Vector(-A.y/L,A.x/L);
}

int v, T, x, y, r, xx0, yy0, n;

struct Circle{
	Point o;
	double r;
	Circle(double x = 0, double y = 0, double r = 0) : o(Point(x, y)), r(r) { }
}cir[maxn], c0;

const double pi = acos(-1);

int main(){
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
#endif
	scanf("%d%d%d%d", &xx0, &yy0, &v, &T);
	c0 = Circle(xx0, yy0, 1. * v * T);
	scanf("%d", &n);

	vector<pair<double, int> >q;
	for(int i = 1; i <= n; ++i){
		scanf("%d%d%d", &x, &y, &r);
		cir[i] = Circle(x, y, r);
		ll dis = (ll)(xx0 - x) * (xx0 - x) + (ll)(yy0 - y) * (yy0 - y);
		if(dis <= (ll)r * r){
			printf("1.0\n");
			return 0;
		}
		if(dis >= (ll)r * r + c0.r * c0.r + 2 * r * c0.r - eps) continue;
		
		double a = min(c0.r, sqrt(dis - (ll)r * r)), b = sqrt(dis), c = r;
		double co = (a * a + b * b - c * c) / (2 * a * b);
		double ang_delta = acos(co);
		if(ang_delta < 0) ang_delta += 2 * pi;
		double ang0 = atan2((cir[i].o - c0.o).y, (cir[i].o - c0.o).x);
		if(ang0 < 0) ang0 += 2 * pi;
		double ang_l = ang0 - ang_delta, ang_r = ang0 + ang_delta;
		while(ang_l < 0) ang_l += 2 * pi;
		while(ang_r > 2 * pi) ang_r -= 2 * pi;
		ang_l -= eps, ang_r += eps;
		q.pb(mkp(ang_r, -1));
		q.pb(mkp(ang_l, 1));
		if(ang_l > ang_r){
			q.pb(mkp(0., 1));
			q.pb(mkp(2 * pi, -1));
		}
	}
	sort(all(q));
	int now = 0;
	double ans = 0, last = 0;
	for(auto v : q){
		if(now > 0) ans += v.fi - last;
		now += v.se;
		last = v.fi;
	}
	printf("%.8f\n", ans / (2 * pi));
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
                BUG
*/
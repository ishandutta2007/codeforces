#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#include <map>
#include <iomanip>
using namespace std;

typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
const double eps = 1e-9;
const double PI = acos(-1.0);

struct Point
{
	double x,y;
	Point(double _x=0,double _y=0):
	  x(_x),
	  y(_y)
	  {}
    void initVect(const Point& a,const Point& b)
	{
		x = b.x-a.x;
		y = b.y-a.y;
		normalize();
	}
	void rotate(double alpha)
	{
		double _x=x;
		double _y=y;
		x = _x*cos(alpha)-_y*sin(alpha);
		y = _x*sin(alpha)+_y*cos(alpha);
	}
	void show(ostream& cout)
	{
		cout << x << " " << y << endl;
	}
	double length()
	{
		return sqrt(x*x+y*y);
	}
	void normalize()
	{
		double len=length();
		x /= len;
		y /= len;
	}
};

bool cmpX(const Point& a,const Point& b)
{
	return (a.x<b.x);
}

bool cmpY(const Point& a,const Point& b)
{
	return (a.y<b.y);
}

long long w,h,a;

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	cout << fixed << setprecision(15);
	cin >> w >> h >> a;
	if (a==90)
		cout << min(w,h)*min(w,h) << endl;
	else
	if (a==0)
		cout << w*h << endl;
	else
	{
		
		Point p1(w/2.0,-h/2.0);
		Point p2(w/2.0,h/2.0);
		Point p3(-w/2.0,h/2.0);
		Point p4(-w/2.0,-h/2.0);
		double alpha=PI/180.0*a;
		p1.rotate(alpha);
		p2.rotate(alpha);
		p3.rotate(alpha);
		p4.rotate(alpha);
		
		vector<Point> polMY,polPY,polMX,polPX;
		Point v;
		double len,x,y;

		v.initVect(p1,p2);
		len=(w/2.0-p1.x)/v.x;
		y=p1.y+v.y*len;
		if (y<=h/2.0 && y>=-h/2.0)
		{
			polPX.push_back(Point(w/2.0,y));
			polMX.push_back(Point(-w/2.0,-y));
		}
		len=(h/2.0-p1.y)/v.y;
		x=p1.x+v.x*len;
		if (x<=w/2.0 && x>=-w/2.0)
		{
			polPY.push_back(Point(x,h/2.0));
			polMY.push_back(Point(-x,-h/2.0));
		}
		len=(-w/2.0-p1.x)/v.x;
		y=p1.y+v.y*len;
		if (y<=h/2.0 && y>=-h/2.0)
		{
			polMX.push_back(Point(-w/2.0,y));
			polPX.push_back(Point(w/2.0,-y));
		}
		len=(-h/2.0-p1.y)/v.y;
		x=p1.x+v.x*len;
		if (x<=w/2.0 && x>=-w/2.0)
		{
			polMY.push_back(Point(x,-h/2.0));
			polPY.push_back(Point(-x,h/2.0));
		}

		v.initVect(p4,p1);
		len=(-h/2.0-p4.y)/v.y;
		x=p4.x+v.x*len;
		if (x<=w/2.0 && x>=-w/2.0)
		{
			polMY.push_back(Point(x,-h/2.0));
			polPY.push_back(Point(-x,h/2.0));
		}
		len=(w/2.0-p4.x)/v.x;
		y=p4.y+v.y*len;
		if (y<=h/2.0 && y>=-h/2.0)
		{
			polPX.push_back(Point(w/2.0,y));
			polMX.push_back(Point(-w/2.0,-y));
		}
		len=(h/2.0-p4.y)/v.y;
		x=p4.x+v.x*len;
		if (x<=w/2.0 && x>=-w/2.0)
		{
			polPY.push_back(Point(x,h/2.0));
			polMY.push_back(Point(-x,-h/2.0));
		}
		len=(-w/2.0-p4.x)/v.x;
		y=p4.y+v.y*len;
		if (y<=h/2.0 && y>=-h/2.0)
		{
			polMX.push_back(Point(-w/2.0,y));
			polPX.push_back(Point(w/2.0,-y));
		}
		
		sort(polPY.begin(), polPY.end(), cmpX);
		sort(polMY.begin(), polMY.end(), cmpX);
		sort(polPX.begin(), polPX.end(), cmpY);
		sort(polMX.begin(), polMX.end(), cmpY);

		vector<Point> pol;
		for (int i=0; i<polMY.size(); i++)
			pol.push_back(polMY[i]);
		for (int i=0; i<polPX.size(); i++)
			pol.push_back(polPX[i]);
		for (int i=polPY.size()-1; i>=0; i--)
			pol.push_back(polPY[i]);
		for (int i=polMX.size()-1; i>=0; i--)
			pol.push_back(polMX[i]);

		double area=0.0;
		for (int i=0; i<pol.size(); i++)
		{
			int j=(i+1)%pol.size();
			area += abs((pol[i].x*pol[j].y-pol[i].y*pol[j].x)/2.0);
		}
		cout << area << endl;
	}
	return 0;
}
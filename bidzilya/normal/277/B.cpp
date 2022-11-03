#include <iostream>
#include <queue>
#include <string>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const double PI = acos(-1.0);
typedef pair<int,int> point;
typedef pair<double,double> vect;

vect rotate(const vect& v, double alpha)
{
	return vect(v.first*cos(alpha)-v.second*sin(alpha),
			v.first*sin(alpha)+v.second*cos(alpha));
}

vector<point> getPolygon(int n,int r,vect v)
{
	double alpha = 2*PI/n;
	vector<point> res;
	for (int i=0; i<n; i++)
	{
		int x = r*v.first;
		int y = r*v.second;
		res.push_back(point(x,y));
		v = rotate(v, alpha);
	}
	return res;
}

void show(const vector<point>& a)
{
	for (int i=0; i<a.size(); i++)
		cout << a[i].first << " " << a[i].second << endl;
}

int main()
{
	#ifndef ONLINE_JUDGE 
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int n,m;
	cin >> n >> m;
	if (m==3 && n>4){cout << -1 << endl; return 0;}
	show(getPolygon(m, 1e8, vect(1,0)));
	
	show(getPolygon(n-m, 1e4, rotate(vect(1,0), 2*PI/39)));
	return 0;
}
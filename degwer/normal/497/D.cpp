#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
double eps = 1e-9;
double pi = 3.1415926535897932384626433832;
double inf = 1e+100;
double add(double a, double b)
{
	return a + b;
}
class P
{
public:
	double x, y;
	P() {}
	P(double x, double y) :x(x), y(y) {}//
	P operator + (P p)
	{
		return P(add(x, p.x), add(y, p.y));
	}
	P operator - (P p)
	{
		return P(add(x, -p.x), add(y, -p.y));
	}
	P operator * (P p)
	{
		return P(add(x*p.x, -y*p.y), add(x*p.y, y*p.x));
	}
	P operator / (P p)
	{
		return P(add(x*p.x, y*p.y) / add(p.x*p.x, p.y*p.y), add(-x*p.y, y*p.x) / add(p.x*p.x, p.y*p.y));
	}
	bool operator < (P p)const
	{
		if (p.x - x>eps)return true;
		if (p.x - x<-eps)return false;
		return y<p.y;
	}
	double arg()
	{
		return atan2(y, x);
	}
};
double dot(P p, P q)
{
	return add(p.x*q.x, p.y*q.y);
}
double det(P p, P q)
{
	return add(p.x*q.y, -p.y*q.x);
}
double abs(P p)
{
	return sqrt(p.x*p.x + p.y*p.y);
}
P univ(P p)
{
	return p / P(abs(p), 0);
}
typedef pair<P, P>segm;
typedef vector<P>poly;
typedef pair<P, double>circ;
P getcross(segm a, segm b)
{
	if (det(a.first - a.second, b.first - b.second) == 0.0) { abort(); }
	else
	{
		return a.first + (a.second - a.first)*P(det(b.second - b.first, b.first - a.first) / det(b.second - b.first, a.second - a.first), 0);
	}
}
bool ison(segm a, P b)
{
	if (fabs(det(a.second - a.first, b - a.first))>eps)return false;
	if (dot(a.second - b, a.first - b) <= 0.0 + eps)return true;
	return false;
}
bool iscross(segm a, segm b)
{
	if (fabs(det(a.first - a.second, b.first - b.second))<eps)
	{
		/*if(ison(a,b.first)||ison(a,b.second)||ison(b,a.first)||ison(b,a.second))return true;
		else return false;*/return false;
	}
	else
	{
		P c = getcross(a, b);
		if (ison(a, c) && ison(b, c))return true;
		else return false;
	}
}
double distsP(segm a, P b)
{
	return fabs(det(a.second - a.first, b - a.first) / abs(a.first - a.second));
}
P foot(segm a, P b)
{
	double d = distsP(a, b);
	P u = univ(a.first - a.second)*P(0, 1);
	if (fabs(det(a.first - a.second, b + u*P(d, 0) - a.second))>eps)u = P(0, 0) - u;
	return b + u*P(d, 0);
}
P symP(segm a, P b)
{
	return foot(a, b) + foot(a, b) - b;
}
pair<P, P> getcrosssc(circ a, segm b)
{
	if (distsP(b, a.first)>a.second + eps) { abort(); }
	else
	{
		double d = distsP(b, a.first);
		P u = univ(b.second - b.first)*P(0, 1);
		if (fabs(det(b.second - b.first, a.first + u*P(d, 0) - b.first))>eps)u = P(0, 0) - u;
		double h = sqrt(max(0.0, a.second*a.second - d*d));
		return make_pair(a.first + u*P(d, 0) + P(h, 0)*univ(b.second - b.first), a.first + u*P(d, 0) - P(h, 0)*univ(b.second - b.first));
	}
}
bool iscrosssc(circ a, segm b)
{
	if (distsP(b, a.first)>a.second + eps)return false;
	pair<P, P> z = getcrosssc(a, b);
	if (ison(b, z.first) || ison(b, z.second))return true;
	return false;
}
int main()
{
	P a;
	scanf("%lf%lf", &a.x, &a.y);
	vector<P>va;
	int na;
	scanf("%d", &na);
	for (int i = 0; i < na; i++)
	{
		P z;
		scanf("%lf%lf", &z.x, &z.y);
		va.push_back(z);
	}
	P b;
	scanf("%lf%lf", &b.x, &b.y);
	int nb;
	scanf("%d", &nb);
	vector<P>vb;
	for (int i = 0; i < nb; i++)
	{
		P z;
		scanf("%lf%lf", &z.x, &z.y);
		vb.push_back(z);
	}
	for (int i = 0; i < nb; i++)
	{
		P z = vb[i];
		for (int j = 0; j < na; j++)
		{
			if (iscrosssc(make_pair(a + z - b, abs(b - a)), make_pair(va[j], va[(j + 1) % na])))
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	swap(na, nb);
	swap(a, b);
	swap(va, vb);
	for (int i = 0; i < nb; i++)
	{
		P z = vb[i];
		for (int j = 0; j < na; j++)
		{
			if (iscrosssc(make_pair(a + z - b, abs(b - a)), make_pair(va[j], va[(j + 1) % na])))
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
}
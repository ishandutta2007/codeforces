#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<lli, lli> pii;

const double PI = 3.14159265358979323;

struct cm {
	bool operator() (const pii& a, const pii& b)
	{
		if(a.first < b.first)
			return true;
		else if(a.first == b.first && a.second < b.second)
			return true;
		return false;
	}
} comp;

double cross(pii O, pii A, pii B)
{
	return (double) (O.first-A.first)*(O.second-B.second)-(O.second-A.second)*(O.first-B.first);
}

double dabs(double a)
{
	return (a > 0) ? a : -a;
}
double dist(pii A, pii B)
{
	return sqrt((double) (A.first-B.first)*(A.first-B.first)+(A.second-B.second)*(A.second-B.second));
}
double area(pii A, pii O, pii B)
{
	return 0.5*dabs( O.first*A.second+O.second*B.first+A.first*B.second-B.first*A.second-O.first*B.second-O.second*A.first );
}
void show(vector<pii >& pts, int k)
{
	for(int i=0;i<k;++i)
		cerr << "  " << pts[i].first << "," << pts[i].second;
	cerr << endl;
}
double angle(pii O, pii A, pii B)
{
	return asin(cross(O, A, B)/dist(O, A)/dist(O, B));
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	vector<pii > pts(n), opts(n);
	int a, b;
	for(int i=0;i<n;++i)
	{
//		cin >> pts[i].first >> pts[i].second;
		cin >> a >> b;
		opts[i].first = a;
		opts[i].second = b;
	}
/*
	//convex hull!!
	sort(pts.begin(), pts.end(), comp);
	vector<pii> opts(n*2), pl(n*2);
	int k = 0;
	for(int i=0;i<n;++i)
	{
		while(k > 1 && cross(opts[k-1], opts[k-2], pts[i]) <= 0)
		{
			--k;
		}
		opts[k++] = pts[i];
		show(opts, k);
	}
	int pk =0;
	for(int i=0;i<n;++i)
	{
		while(pk > 1  && cross(pl[pk-1], pl[pk-2], pts[i]) >= 0)
			--pk;
		pl[pk++] = pts[i];
		show(pl, pk);
	}

	for(int i=pk-2;i>0;--i,++k)
		opts[k] = pl[i];

	
*/

	// n^2 check for intersections!
	double minIntersect = 1000000000000000.0;
	for(int i=0;i<n;++i)
	{
		for(int j=i+1;j<n;++j)
		{
			if(dist(opts[i], opts[j]) < minIntersect)
				minIntersect = dist(opts[i], opts[j])/2;
		}
	}

	double base, h, aa, ab, ac;
	// distance from each point to each edge
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
		{
			base = dist(opts[j], opts[(j+1)%n]);
			h = 2*area(opts[j], opts[(j+1)%n], opts[i])/base;
			aa = dabs(angle(opts[j], opts[(j+1)%n], opts[i]));
			ab = dabs(angle(opts[(j+1)%n], opts[i], opts[j]));
			ac = dabs(angle(opts[i], opts[j], opts[(j+1)%n]));
			if(h < minIntersect && ac < PI/2 && ab < PI/2 && aa < PI/2)
				minIntersect = h;
		}
	}

	// check for lack of convexity
	for(int i=0;i<n && n != 3;++i)
	{
		base = dist(opts[i], opts[(i+2)%n]);
		h = 2*area(opts[i], opts[(i+1)%n], opts[(i+2)%n])/base;
		if(h/2 < minIntersect)
			minIntersect = h/2;
	}

	cout << setprecision(10) << minIntersect << endl;
	

	return 0;
}
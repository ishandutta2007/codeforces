#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct el
{
	el() {}
	el(double _val, int _id, int _pos, int _cov = 0) {val = _val; id = _id; pos = _pos; cov = _cov;}
	double val;
	int id;
	int pos;
	int cov;
};

bool cmp_one(const el &a, const el &b)
{
	if (a.pos != b.pos)
	{
		return a.pos < b.pos;
	}
	return a.id < b.id;
}

bool cmp_two(const el &a, const el &b)
{
	if (a.pos != b.pos)
		return a.pos > b.pos;
	return a.id < b.id;
}

int n, m;
int a[100020], h[100020], l[100020], r[100020];

int b[100020], z[100020];
double ps[100020];

vector<el> v;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &a[i], &h[i], &l[i], &r[i]);
	}
	
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d", &b[i], &z[i]);
		ps[i] = 1.0;
	}
	
	// go right
	v.clear();
	for (int i = 0; i < n; ++i)
	{
		if (r[i] != 100)
		{
			v.push_back(el((100.0 - r[i]) / 100.0, -1, a[i] + 1));
			v.push_back(el(100.0 / (100.0 - r[i]), -1, a[i] + h[i] + 1));
		}
		else
		{
			v.push_back(el(1.0, -1, a[i] + 1, 1));
			v.push_back(el(1.0, -1, a[i] + h[i] + 1, -1));
		}
	}
	for (int i = 0; i < m; ++i)
	{
		v.push_back(el(-1, i, b[i]));
	}
	sort(v.begin(), v.end(), cmp_one);
	
	double pr = 1.0;
	int cov = 0;
	for (int i = 0; i < (int) v.size(); i++)
	{
		if (v[i].id == -1)
		{
			pr *= v[i].val;
			cov += v[i].cov;
		}
		else
		{
			if (cov)
				ps[v[i].id] = 0;
			else
				ps[v[i].id] *= pr;
		}
	}
	
	//~ for (int i = 0; i < m; ++i)
		//~ printf("%d %lf\n", i, ps[i]);
	
	// go left
	v.clear();
	for (int i = 0; i < n; ++i)
	{
		if (l[i] != 100)
		{
			v.push_back(el((100.0 - l[i]) / 100.0, -1, a[i] - 1));
			v.push_back(el(100.0 / (100.0 - l[i]), -1, a[i] - h[i] - 1));
		}
		else
		{
			v.push_back(el(1.0, -1, a[i] - 1, 1));
			v.push_back(el(1.0, -1, a[i] - h[i] - 1, -1));
		}
	}
	for (int i = 0; i < m; ++i)
	{
		v.push_back(el(-1, i, b[i]));
	}
	sort(v.begin(), v.end(), cmp_two);
	
	pr = 1.0;
	cov = 0;
	for (int i = 0; i < (int) v.size(); i++)
	{
		if (v[i].id == -1)
		{
			pr *= v[i].val;
			cov += v[i].cov;
		}
		else
		{
			if (cov)
				ps[v[i].id] = 0;
			else
				ps[v[i].id] *= pr;
		}
	}
	
	//~ for (int i = 0; i < m; ++i)
		//~ printf("%d %lf\n", i, ps[i]);
	
	double ans = 0.0;
	for (int i = 0; i < m; i++)
	{
		ans += z[i] * ps[i];
	}
	
	printf("%.10lf\n", ans);
	return 0;
}
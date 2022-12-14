#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <vector>
#include <functional>
#include <cmath>
using namespace std;

const double eps = 1e-7;

struct el
{
	double fx, a, b;

};

bool smfi(const el& f, const el& e)
{
	if (abs(f.a - e.a) < eps)
		return f.b + eps < e.b;
	return f.a + eps < e.a;
}

bool bifi(const el& e, const el& f)
{
	return f.a > e.a + eps;
}

inline double eval(const el &e, const double &x)
{
	return e.a * x + e.b;
}

inline double cr(const el &e, const el &f)
{
	return (e.b-f.b)/(f.a-e.a);
}

typedef pair<int,int> pii;

int n, k;
vector<el> v[512];
vector<el> st;
int y[512];
int mx[512];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		double old = 0, nne = 0;
		for (int j = 0; j < k; ++j)
		{
			for (int l = 0; l < (int) v[j].size(); ++l)
			{
				double ne = 1.0+j;
				if (l+1 < (int) v[j].size())
					ne = v[j][l+1].fx;
				old += (ne-v[j][l].fx)*(eval(v[j][l], v[j][l].fx) + eval(v[j][l], ne))/2.0;
			}
		}
		for (int j = 0; j <= k; ++j)
		{
			scanf("%d", &y[j]);
		}
		
		for (int j = 0; j < k; ++j)
		{
			el e;
			e.a = y[j+1] - y[j];
			e.b = y[j] - e.a*j;
			//~ printf("Y %d %d :: %lf %lf\n", j, y[j], e.a, e.b);
			vector<el>::iterator it = lower_bound(v[j].begin(), v[j].end(), e, smfi);
			bool fi = 0;
			if (it != v[j].end())
			{
				if (abs(it->a - e.a) < eps)
				{
					it->b = max(it->b, e.b);
					fi = 1;
				}
			}
			if (it != v[j].begin())
			{
				--it;
				if (abs(it->a - e.a) < eps)
				{
					it->b = max(it->b, e.b);
					fi = 1;
				}
			}
			if (!fi)
				v[j].push_back(e);
			sort(v[j].begin(), v[j].end(), smfi);
			//~ for (int l = 0; l < (int) v[j].size(); ++l)
			//~ {
				//~ printf("%lf %lf\n", v[j][l].a, v[j][l].b);
			//~ }
			st.clear();
			for (int l = 0; l < (int) v[j].size(); ++l)
			{
				while ((int) st.size() >= 2 && cr(st[st.size()-2], st[st.size()-1]) > eps + cr(st[st.size()-2], v[j][l]))
				{
					//~ printf("AA_POPING %lf %lf :: %lf %lf\n", st.back().a, st.back().b, cr(st[st.size()-2], v[j][l]), cr(st[st.size()-1], v[j][l]));
					st.pop_back();
				}
				while ((int) st.size() >= 1 && cr(st.back(), v[j][l]) + eps < (double) j)
				{
					//~ printf("POPING %lf %lf :: %lf\n", st.back().a, st.back().b, cr(st.back(), v[j][l]));
					st.pop_back();
				}
				if (!st.size())
				{
					v[j][l].fx = j;
					st.push_back(v[j][l]);
				}
				else if ((int) st.size() >= 1 && cr(st.back(), v[j][l]) + eps < 1.0 + j)
				{
					v[j][l].fx = cr(st.back(), v[j][l]);
					st.push_back(v[j][l]);
				}
			}
			v[j] = st;

		}
		
		for (int j = 0; j < k; ++j)
		{
			//~ printf("O %d %d %lf %lf %lf [%lf %lf - %lf]\n", j, v[j].size(), v[j][0].a, v[j][0].b, v[j][0].fx,
			//~ v[j][1].a, v[j][1].b, v[j][1].fx);
			for (int l = 0; l < (int) v[j].size(); ++l)
			{
				double ne = 1.0+j;
				if (l+1 < (int) v[j].size())
					ne = v[j][l+1].fx;
				//~ printf("NE %lf %lf __ %lf %lf\n", ne, v[j][l].fx, nne, eval(v[j][l], v[j][l].fx));
				nne += (ne-v[j][l].fx)*(eval(v[j][l], v[j][l].fx) + eval(v[j][l], ne))/2.0;
			}
		}
		//~ fprintf(stderr, "%lf %lf\n", nne, old);
		printf("%.12lf\n", nne-old);
	}
	
	return 0;
}
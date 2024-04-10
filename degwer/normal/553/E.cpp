#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
class cd
{
public:
	float x, y;
	cd() { x = 0, y = 0; }
	cd(double x, double y) :x(x), y(y) {}//
	cd operator + (cd p)
	{
		return cd(x + p.x, y + p.y);
	}
	cd operator - (cd p)
	{
		return cd(x - p.x, y - p.y);
	}
	cd operator * (cd p)
	{
		return cd(x*p.x - y*p.y, x*p.y + y*p.x);
	}
};
typedef pair<vector<cd>, vector<cd> >pvcd;
double pi = 3.1415926535897932384626433;
#define LOG 16
class FFT
{
public:
	cd dat[2][1 << LOG];
	cd omega[1 << LOG], romega[1 << LOG];
	int seg[1 << LOG];
	void init(int lg)
	{
		for (int i = 0; i < (1 << lg); i++)omega[i] = cd(cos(pi*i * 2 / double(1 << lg)), sin(pi*i * 2 / double(1 << lg)));
		for (int i = 0; i < (1 << lg); i++)romega[i] = cd(cos(pi*i * 2 / double(1 << lg)), -sin(pi*i * 2 / double(1 << lg)));
		for (int i = 0; i < (1 << lg); i++)
		{
			int t = 0;
			for (int j = 0; j < lg; j++)if (i&(1 << j))t += 1 << (lg - j - 1);
			seg[i] = t;
		}
	}
	vector<cd>transform(vector<cd>v, int lg, bool pal)//TCY2^lg, paltrue, tfalse
	{
		int cur = 0;
		v.resize(1 << lg);
		for (int i = 0; i < (1 << lg); i++)dat[0][seg[i]] = v[i];
		for (int i = lg - 1; i >= 0; i--)
		{
			for (int j = 0; j < (1 << lg); j += (1 << (lg - i)))
			{
				int s = 1 << (lg - i - 1);
				if (pal)
				{
					for (int k = 0; k < s; k++)dat[1 - cur][j + k] = dat[cur][j + k] + dat[cur][j + s + k] * omega[k << i];
					for (int k = 0; k < s; k++)dat[1 - cur][j + s + k] = dat[cur][j + k] - dat[cur][j + s + k] * omega[k << i];
				}
				else
				{
					for (int k = 0; k < s; k++)dat[1 - cur][j + k] = dat[cur][j + k] + dat[cur][j + s + k] * romega[k << i];
					for (int k = 0; k < s; k++)dat[1 - cur][j + s + k] = dat[cur][j + k] - dat[cur][j + s + k] * romega[k << i];
				}
			}
			cur = 1 - cur;
		}
		vector<cd>ret;
		for (int i = 0; i < (1 << lg); i++)ret.push_back(dat[cur][i]);
		return ret;
	}
	pvcd transform_2(vector<double>va, vector<double>vb, int lg, bool pal)//2Ctransform 
	{
		va.resize(1 << lg);
		vb.resize(1 << lg);
		vector<cd>r;
		r.resize(1 << lg);
		for (int i = 0; i < (1 << lg); i++)r[i] = cd(va[i], vb[i]);
		r = transform(r, lg, pal);
		vector<cd>ra, rb;
		ra.resize(1 << lg);
		rb.resize(1 << lg);
		for (int i = 0; i < (1 << lg); i++)
		{
			int j = ((1 << lg) - i)&((1 << lg) - 1);
			ra[i] = cd((r[i] + r[j]).x, (r[i] - r[j]).y) * cd(0.5, 0);
			rb[i] = cd((r[i] + r[j]).y, -(r[i] - r[j]).x) * cd(0.5, 0);
			//printf("%d %lf %lf    %lf %lf  %lf %lf\n", i, r[i].x, r[i].y, ra[i].x, ra[i].y, rb[i].x, rb[i].y);
		}
		return make_pair(ra, rb);
	}
};
#define SIZE 32768
FFT fft[17];
class segtree
{
public:
	double seg[1 << LOG];
	vector<cd>tim[20];
	double now[1 << LOG];
	void init(vector<double>t,int lg)
	{
		int pt = 0;
		for (int d = 0; d <= lg; d++)
		{
			vector<cd>z;
			for (int i = pt; i < (1 << d); i++)z.push_back(cd(t[i], 0));
			pt = 1 << d;
			tim[d] = fft[d].transform(z, d, true);
			//for (int i = 0; i < tim[d].size(); i++)if(fabs(tim[d][i].x)>1e15||fabs(tim[d][i].y)>1e15)printf("%d %d  %d %d  %lf %lf\n", d,i,z.size(),1<<d,tim[d][i].x,tim[d][i].y);
		}
	}
	double add(int a, double t)
	{
		now[a] += t*tim[0][0].x;
		seg[a] = t;
		int s = 1;
		for (int d = 0;; d++)
		{
			vector<cd>z;
			for (int i = a - s + 1; i <= a; i++)z.push_back(cd(seg[i],0));
			//printf("\n\n\n\n");
			//for (int i = 0; i < z.size(); i++)printf("%lf ", z[i]); printf("\n");
			z = fft[d + 1].transform(z, d + 1, true);
			//for (int i = 0; i < z.size(); i++)printf("%lf ", z[i]); printf("\n");
			for (int i = 0; i < z.size(); i++)z[i] = z[i] * tim[d + 1][i];
			//for (int i = 0; i < z.size(); i++)printf("%lf ", z[i]); printf("\n");
			z = fft[d + 1].transform(z, d + 1, false);
			//for (int i = 0; i < z.size(); i++)printf("%lf ", z[i]); printf("\n");
			for (int i = 0; i < z.size(); i++)now[i + a + 1] += z[i].x / double(1 << (d + 1));
			if ((a&(1 << d)) == 0)break;
			s <<= 1;
		}
		return now[a];
	}
};
segtree tree[100];
int dist[50][50];
double cst[100][20001];
double rui[100][20001];
int frm[100], to[100], len[100];
double dp[20001][50];
int main()
{
	/*int num;
	scanf("%d", &num);
	vector<double>va, vb;
	va.push_back(0);
	vb.push_back(0);
	for (int i = 0; i < num; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		va.push_back(za);
		vb.push_back(zb);
	}
	fft[0].init(18);
	pvcd r = fft[0].transform_2(va, vb, 18, true);
	for (int i = 0; i < r.first.size(); i++)r.first[i] = r.first[i] * r.second[i];
	r.first = fft[0].transform(r.first, 18, false);
	for (int i = 1; i <= num + num; i++)printf("%d\n", int(floor(r.first[i].x / (1 << 18) + 0.5)));*/
	int num, way, gen, pen;
	scanf("%d%d%d%d", &num, &way, &gen, &pen);
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)dist[i][j] = 1000000000;
	for (int i = 0; i < num; i++)dist[i][i] = 0;
	for (int i = 0; i < 17; i++)fft[i].init(i);
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--, zb--;
		dist[za][zb] = min(dist[za][zb], zc);
		frm[i] = za, to[i] = zb, len[i] = zc;
		for (int j = 1; j <= gen; j++)scanf("%lf", &cst[i][j]), cst[i][j] /= 100000, rui[i][j] = rui[i][j - 1] + cst[i][j];
		vector<double>z;
		z.resize(1 << 16);
		for (int j = 0; j < gen; j++)z[j] = cst[i][j + 1];
		tree[i].init(z, 16);
	}
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)for (int k = 0; k < num; k++)dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
	for (int i = 0; i < num; i++)dp[0][i] = (double)dist[i][num - 1] + double(pen);
	dp[0][num - 1] = 0;
	for (int x = 0; x < gen; x++)
	{
		for (int i = 0; i < num; i++)dp[x + 1][i] = (double)dist[i][num - 1] + double(pen);
		dp[x + 1][num - 1] = 0;
		for (int i = 0; i < way; i++)
		{
			double z = tree[i].add(x, dp[x][to[i]]);
			dp[x + 1][frm[i]] = min(dp[x + 1][frm[i]], (double)len[i] + z + (double)(rui[i][gen] - rui[i][x + 1])*(dist[to[i]][num - 1] + pen));
		}
		//for (int i = 0; i < num; i++)printf("%lf ", dp[x + 1][i]); printf("\n");///
	}
	printf("%.10lf\n", dp[gen][0]);
}
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string>
#include<iostream>
using namespace std;
class cd
{
public:
	double x, y;
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
#define LOG 20
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
FFT fft;
int main()
{
	int data;
	scanf("%d", &data);
	for (int p = 0; p < data; p++)
	{
		int num;
		scanf("%d", &num);
		string s;
		cin >> s;
		int lg = 0;
		for (;;)
		{
			if (num * 2 <= (1 << lg))break;
			lg++;
		}
		fft.init(lg);
		vector<double>v1, v2;
		v1.resize(num * 2);
		v2.resize(num * 2);
		for (int i = 0; i < num; i++)
		{
			if (s[i] == 'V')v1[i] = 1;
			else if (s[i] == 'K')v2[num - i] = 1;
		}
		pvcd zz = fft.transform_2(v1, v2, lg, true);
		vector<cd>v;
		v.resize(1 << lg);
		for (int i = 0; i < (1 << lg); i++)v[i] = zz.first[i] * zz.second[i];
		v = fft.transform(v, lg, false);
		vector<int>ans;
		ans.resize(num + 1);
		//for (int i = 0; i < (1 << lg); i++)printf("%lf %lf\n", v1[i].x, v1[i].y);
		for (int i = 0; i < num + num; i++)if (v[i].x / (1 << lg) > 0.5)ans[abs(num - i)] = 1;
		vector<int>ret;
		for (int i = 1; i <= num; i++)
		{
			for (int j = i; j <= num; j += i)if (ans[j] == 1)ans[i] = 1;
			if (ans[i] == 0)ret.push_back(i);
		}
		printf("%d\n", ret.size());
		for (int i = 0; i < ret.size(); i++)printf("%d ", ret[i]);
		printf("\n");
	}
}
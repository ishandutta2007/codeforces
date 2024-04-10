#include<stdio.h>
#include<vector>
#include<algorithm>
#include<complex>
using namespace std;
#define SIZE 1048576
#define LOG 20
typedef long long ll;
ll mod = 469762049;//2^26*7+1, 30
//ll mod = 167772161;//2^25*5+1, 17
ll po(ll a, ll b)
{
	if (b == 0)return 1;
	ll z = po(a, b / 2);
	z *= z;
	z %= mod;
	if (b % 2 == 1)
	{
		z *= a;
		z %= mod;
	}
	return z;
}
vector<ll>fft(vector<ll>vec, ll p)
{
	if (vec.size() == 1)return vec;
	vector<ll>ve, vo;
	for (int i = 0; i < vec.size(); i += 2)
	{
		ve.push_back(vec[i]);
		vo.push_back(vec[i + 1]);
	}
	ve = fft(ve, (p*p) % mod);
	vo = fft(vo, (p*p) % mod);
	vector<ll>ret;
	ll now = 1;
	for (int i = 0; i < ve.size(); i++)
	{
		ret.push_back((ve[i] + vo[i] * now) % mod);
		now = now*p;
		now %= mod;
	}
	for (int i = 0; i < ve.size(); i++)
	{
		ret.push_back((ve[i] + vo[i] * now) % mod);
		now = now*p;
		now %= mod;
	}
	return ret;
}
vector<ll>mul(vector<ll>a, vector<ll>b)
{
	int t = a.size();
	for (int i = a.size(); i < SIZE; i++)
	{
		a.push_back(0);
		b.push_back(0);
	}
	ll root = 30;
	root = po(root, 1 << (26 - LOG));
	a = fft(a, root);
	b = fft(b, root);
	vector<ll>ret;
	for (int i = 0; i < a.size(); i++)ret.push_back((a[i] * b[i]) % mod);
	ret = fft(ret, root);
	ll inv = po(SIZE, mod - 2);
	for (int i = 0; i < ret.size(); i++)ret[i] = (ret[i] * inv) % mod;
	vector<ll>rr;
	for (int i = 0; i < t; i++)rr.push_back(ret[i]);
	return ret;
}
int dat[SIZE];
int main()
{
	int num, gen;
	scanf("%d%d", &num, &gen);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		dat[z] = 1;
	}
	vector<ll>v;
	for (int i = 0; i < SIZE; i++)v.push_back(dat[i]);
	v = fft(v, po(30,1<<(26-LOG)));
	for (int i = 0; i < v.size(); i++)v[i] = po(v[i], gen);
	v = fft(v, po(po(30, mod - 2), 1 << (26 - LOG)));
	bool f = false;
	for (int i = 0; i < SIZE; i++)
	{
		if (v[i] != 0)
		{
			if (f)printf(" ");
			f = true;
			printf("%d", i);
		}
	}
	printf("\n");
}
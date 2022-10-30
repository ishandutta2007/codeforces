#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#ifndef ONLINE_JUDGE
#define dbg(x...) do{cout << "\033[32;1m" << #x << "->" ; err(x);} while(0)
void err(){cout << "\033[39;0m" << endl;}
template<template<typename...> class T,typename t,typename... A>
void err(T<t> a,A... x){for (auto v:a) cout << v << ' '; err(x...);}
template<typename T,typename... A>
void err(T a,A... x){cout << a << ' '; err(x...);}
#else
#define dbg(...)
#endif
typedef double LD;
const LD PI = 3.14159265358979;
struct C
{
    LD r, i;
    C(LD r = 0, LD i = 0) : r(r), i(i) {}
    C operator+(const C &a) const
    {
        return C(r + a.r, i + a.i);
    }
    C operator-(const C &a) const
    {
        return C(r - a.r, i - a.i);
    }
    C operator*(const C &a) const
    {
        return C(r * a.r - i * a.i, r * a.i + i * a.r);
    }
};
void FFT(C x[], int n, int p)
{
    for (int i = 0, t = 0; i < n; ++i)
    {
        if (i > t)
            swap(x[i], x[t]);
        for (int j = n >> 1; (t ^= j) < j; j >>= 1)
            ;
    }
    for (int h = 2; h <= n; h <<= 1)
    {
        C wn(cos(p * 2 * PI / h), sin(p * 2 * PI / h));
        for (int i = 0; i < n; i += h)
        {
            C w(1, 0), u;
            for (int j = i, k = h >> 1; j < i + k; ++j)
            {
                u = x[j + k] * w;
                x[j + k] = x[j] - u;
                x[j] = x[j] + u;
                w = w * wn;
            }
        }
    }
    if (p == -1)
        for (int i = 0; i < n; ++i)
            x[i].r /= n;
}
void conv(C a[], C b[], int n)
{
    FFT(a, n, 1);
    FFT(b, n, 1);
    for (int i = 0; i < n; ++i)
        a[i] = a[i] * b[i];
    FFT(a, n, -1);
}
const int maxn=2e6+7;
C A[maxn*2],B[maxn*2],C[maxn*2],D[maxn*2];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	int len=1;
	string a,b;
	cin>>a>>b;
	reverse(b.begin(),b.end());
	while(len<=(a.length()+b.length())) len*=2;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='0') A[i].r=1;
		else C[i].r=1;
	}
	for(int i=0;i<b.length();i++)
	{
		if(b[i]=='0') B[i].r=1;
		else D[i].r=1;
	}
	conv(A,B,len);
	conv(C,D,len);
	for(int i=0;i<=len;i++)
		A[i]=A[i]+C[i];
//	for(int i=0;i<len;i++)
//		dbg(i,b.length()-A[i].r);
	int ans=0;
	for(int i=0;i<a.length()-b.length()+1;i++)
		if((b.length()-int(round(A[b.length()-1+i].r)))%2==0) ans++;
	cout<<ans<<endl;
}
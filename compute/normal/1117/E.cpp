#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(x...) do { cout << "the " << #x << " -> "; err(x); } while (0)
void err() { cout << "" << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
typedef pair<int,int> PII;
typedef long long LL;
LL ex_gcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) { x = 1; y = 0; return a; }
    LL ret = ex_gcd(b, a % b, y, x);
    y -= a / b * x;
    return ret;
}
LL CRT(LL *m, LL *r, LL n) {
    if (!n) return 0;
    LL M = m[0], R = r[0], x, y, d;
    for (int i=1;i<n;i++) {
        d = ex_gcd(M, m[i], x, y);
        if ((r[i] - R) % d) return -1;
        x = (r[i] - R) / d * x % (m[i] / d);
        R += x * M;
        M = M / d * m[i];
        R %= M;
    }
    return R >= 0 ? R : R + M;
}
const int maxn=1e4+7;
vector<int> all[maxn];
int pos[maxn];
char ans[maxn];
int power(int a,int b)
{
	int ret=1;
	for(int i=0;i<b;i++) ret*=a;
	return ret;
}
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	string out[3];
	for(int i=0;i<s.length();i++)
	{
		out[0]+=('a'+i%26);
		out[1]+=('a'+i%25);
		out[2]+=('a'+i%23);
	}
	string res;
	for(int i=0;i<3;i++)
	{
		cout<<"? "<<out[i]<<endl;
		cin>>res;
		for(int j=0;j<res.length();j++)
		{
			all[j].emplace_back(res[j]-'a');
		}
	}
	LL m[3],r[3];
	m[0]=26,m[1]=25,m[2]=23;
	for(int i=0;i<s.length();i++)
	{
		int pos=0;
		for(int j=0;j<3;j++)
		{
			r[j]=all[i][j];
		}
		pos=CRT(m,r,3);
		dbg(pos);
		ans[pos]=s[i];
	}
	ans[s.length()]='\0';
	cout<<"! "<<ans<<endl;
}
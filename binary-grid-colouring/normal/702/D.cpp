#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<stack>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define MP(x,y) make_pair(x,y)  
template <class T1, class T2>inline void getmax(T1 &a, T2 b) { if (b>a)a = b; }  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) { if (b<a)a = b; }
int read()
{
	int v = 0, f = 0;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}

int main() 
{
	ll i,j,k,l,n,m,d,a,b,t,ans;
	cin>>d>>k>>a>>b>>t;
	if(d<=k) // 
		cout<<d*a<<endl;
	else {
		ans = k*a;
		// 
		ans += min((d%k)*b,t+(d%k)*a);
		d/=k;
		d--;
		// 
		ans += min(d*b*k,d*(k*a+t));
		cout<<ans<<endl;
	}
	return 0;
}
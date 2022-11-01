#pragma comment(linker, "/STACK:102400000,102400000")
#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<queue>
#include<set>
#include<stack>
#include <utility>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define pii pair<int,int>
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }  
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N = 2e5+10; 
const int M=100010; 
template <class T1, class T2>inline void getmax(T1 &a, T2 b) {if (b>a)a = b;}  
template <class T1, class T2>inline void getmin(T1 &a, T2 b) {if (b<a)a = b;}
int read()
{
	int v = 0, f = 1;
	char c =getchar();
	while( c < 48 || 57 < c ){
		if(c=='-') f = -1;
		c = getchar();
	}
	while(48 <= c && c <= 57) 
		v = v*10+c-48, c = getchar();
	return v*f;
}
/*
	#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
*/

char c[107];
int main()
{
	cin.getline(c, 110);
	int e;
	for (int i = 0; i < strlen(c); i++)if (c[i] == 'e')e = i;		//e
	int b = c[e + 1] - '0'; // 
	if (e + 2 < strlen(c))		//b
	{
		b *= 10;
		b += c[e + 2] - '0';
		if (e + 3 < strlen(c))b = 100;
	}

	if (e == 3 && c[2] == '0')		//d==0
	{
		cout << c[0];
		if (c[0] != '0')
		while (b--) cout << '0';
	}
	else if (b)		//d!=0b!=0
	{
		bool flag = false;
		if (c[0] != '0')flag = true;
		if(flag)cout << c[0];		
		for (int i = 2; i < e; i++)
		{			
			if (!flag&&c[i] == '0')
			{
				if (i == 1 + b && i + 1 < e)
				{
					cout << "0.";
					flag = true;
				}
			}
			else
			{
				flag = true;
				cout << c[i];
				if (i == 1 + b && i + 1<e)cout << '.';
			}			
		}
		for (int i = e; i <= b + 1; i++) cout << '0';
	}
	else for (int i = 0; i < e; i++)cout << c[i];		//d!=0,b=0
	return 0;
}
#pragma comment(linker, "/STACK:102400000,102400000")
//#include<bits/stdc++.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <bitset>
#include <iomanip>
#include <list>
#include <stack>
#include <utility> 
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
const double eps = 1e-8;  
const int INF = 1e9+7; 
const ll inf =(1LL<<62) ;
const int MOD = 1e9 + 7;  
const ll mod = (1LL<<32);
const int N =1e6+6; 
const int M=100010;
const int maxn=1001;
#define mst(a) memset(a, 0, sizeof(a))
#define M_P(x,y) make_pair(x,y)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
//const int lowbit(int x) { return ((x)&((x)^((x)-1))); } 
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
char a[1010][6];
int n;
ll f[510][510];
int check()
{
	ll temp,sum = 0;
	for (int i = 1;i <= n;i++) sum += f[1][i];
	for (int i = 1;i <= n;i++)
	{
		temp = 0;
		for (int j = 1;j <= n;j++)
			temp += f[i][j];
		if (temp != sum) return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		temp = 0;
		for (int j = 1;j <= n;j++)
			temp += f[j][i];
		if (temp != sum) return 0;
	}
	temp = 0;
	for (int i = 1;i <= n;i++)
	{
		temp += f[i][i];
	}
	
	if (temp != sum) return 0;
	temp = 0;
	for (int i = 1;i <= n;i++)
	{
		temp += f[i][n-i+1];
	}
	if (temp != sum) return 0;
	return 1;
}
int main()
{   
    cin>>n;
    int x,y;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		cin>>f[i][j];
    		if(f[i][j]==0)
    		x=i,y=j;
		}
	}
	if (n == 1){puts("1"); return 0;}
	int xx = 1;
	if (x == 1) xx = 2;
	ll temp = 0;
	for (int i = 1;i <= n;i++)
		temp += f[xx][i];
	for (int i = 1;i <= n;i++)
		temp -= f[x][i];
	if (temp <= 0){puts("-1"); return 0;}
	f[x][y] = temp;
	if (check()) cout<<temp<<endl;
	else {puts("-1"); return 0;}
    return 0; 
}
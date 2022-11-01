#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
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
#define pi acos(-1.0)
#define in freopen("in.txt","r",stdin) 
#define rep(i,j,k) for (int i = j; i <= k; i++)  
#define per(i,j,k) for (int i = j; i >= k; i--)  
#define lson x << 1, l, mid  
#define rson x << 1 | 1, mid + 1, r  
const int lowbit(int x) { return x&-x; }
int read(){ int v = 0, f = 1;char c =getchar();
while( c < 48 || 57 < c ){if(c=='-') f = -1;c = getchar();}
while(48 <= c && c <= 57) v = v*10+c-48, c = getchar();
return v*f;}
/***************************timer******************************/
struct timer
{
   double t;
   timer() { t=clock(); }
   ~timer() { printf("\nruntime %.3f s\n", get_time()); }
   double get_time() { return (clock()-t)/CLOCKS_PER_SEC; }
};
/*************************************************************/
int dp[234][12][4567];
void solve(int x, char tmp[])
{
	int len = strlen(tmp);
	for (int i = 0; i < 12; i++){
		for (int j=0;j<(1 <<(i+1));j++){
			for (int k=0;k+i<len;k++){
				int flag=0;
				for (int h=0; h<=i;h++){
					if (((j>>h)&1)!=tmp[k + h]-'0'){
						flag = 1; break;
					}
				}
				if (!flag){
					dp[x][i][j]=1;break;
				}
			}
		}
	}
}
/*
5
01
10
101
11111
0
3
1 2
6 5
4 4
1
2
0
*/
int len[234];
char tmp1[234][15],tmp2[234][20],tmp3[45];
int n,q;
char s[123][123];
int main()
{
  	n=read();
	for(int i=0;i<n;i++)
	{
		scanf("%s", s[i]);
		solve(i, s[i]);
		int length=strlen(s[i]);
		len[i]=length;
		if (len[i]>=13){ len[i]=14; }
		for (int j=0;j<len[i];j++){
			tmp1[i][j] = s[i][j]; 
			tmp2[i][j] = s[i][length - len[i] + j];
		}
	}
	q=read();
	int a, b;
	for (int i=n;i<n+q;i++)
	{	
		a=read(),b=read();
		a--; b--;
		for (int j=0;j<=11;j++){
			for (int k=0; k<(1<<(j+1));k++){
				dp[i][j][k] = dp[a][j][k] | dp[b][j][k];
			}
		}
		for (int j=0;j<len[a];j++){
			tmp3[j] = tmp2[a][j];
		}
		for (int j=0; j<len[b];j++){
			tmp3[j+len[a]]=tmp1[b][j];
		}
		tmp3[len[a]+len[b]]=0;
		solve(i, tmp3);
		len[i] = len[a] + len[b];
		if (len[i]>=13)len[i] = 14;
		for (int j=0;j<len[a];j++)
		{
			tmp1[i][j]=tmp1[a][j];
		}
		for (int j=0;j+len[a]<len[i];j++)
		{
			tmp1[i][j+len[a]]=tmp1[b][j];
		}
		for (int j=0;j<len[b];j++)
		{
			tmp2[i][j+len[i]-len[b]]=tmp2[b][j];
		}
		for (int j=0;j+len[b]<len[i];j++){
			tmp2[i][j]=tmp2[a][j+len[a]+len[b]-len[i]];
		}
		int ans = 12;
		for (int j=0;j<=11;j++){
			int flag=0;
			for (int k=0; k<(1 <<(j + 1));k++){
				if (dp[i][j][k]==0){
					flag = 1;break;
				}
			}
			if (flag){
				ans = j;break;
			}
		}
		cout<<ans<<endl;
	}
    return 0;
}
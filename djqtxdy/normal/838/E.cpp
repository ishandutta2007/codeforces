#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
string mul(string a,string b){
	int res[Maxk];
	memset(res,0,sizeof(res));
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for (int i=0;i<a.length();i++){
		for (int j=0;j<b.length();j++){
			res[i+j]+=(a[i]-'0')*(b[j]-'0');
		}
	}
	for (int i=0;i<Maxk;i++){
		if (res[i]>=10) {
			res[i+1]+=(res[i]/10);
			res[i]%=10;
		}
	}
	string ret;
	bool flag=false;
	for (int i=Maxk-1;i>=0;i--){
		if (flag || res[i]){
			flag=true;
			ret=ret+(char)(res[i]+'0');
		}
	}
	if (ret=="") ret="0";
	return ret;
}
string add(string a,string b){
	if (a.length()<b.length()) swap(a,b);
	while (a.length()!=b.length()){
		b='0'+b;
	}
	for (int i=a.length()-1;i>=0;i--){
		a[i]+=(b[i]-'0');
		if (a[i]>'9' && i){
			a[i]-=10;
			a[i-1]++;
		}
	}
	if (a[0]>'9'){
		a[0]-=10;
		a='1'+a;
	}
	return a;
}

// cf IO: I64d
// atcoder IO: 
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=2505;
double x[Maxn],y[Maxn];
double dp[Maxn][Maxn][2];
int n;
double dist(int a,int b){
	if (a>n) a-=n;
	if (a<=0) a+=n;
	if (b>n) b-=n;
	if (b<=0) b+=n;
	return sqrt((double)(x[a]-x[b])*(x[a]-x[b])+(double)(y[a]-y[b])*(y[a]-y[b]));
}
double f(int a,int b,int c){
	if (a>n) a-=n;
	if (a<=0) a+=n;
	if (b>n) b-=n;
	if (b<=0) b+=n;
	return dp[a][b][c];
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		int t1,t2;
		scanf("%d %d",&t1,&t2);
		x[i]=(double)t1;
		y[i]=(double)t2;
	}
	for (int i=1;i<=n;i++){
		dp[i][i][0]=0.0;
		dp[i][i][1]=0.0;
	}
	double ans=0.0;
	for (int len=2;len<=n;len++){
		for (int i=1;i<=n;i++){
			int j=i+len-1;
			if (j>n) j-=n;
			// dp[i][j][0] stop at i;
			dp[i][j][0]=max(f(i+1,j,0)+dist(i,i+1),f(i+1,j,1)+dist(i,j));
			// dp[i][j][1] stop at j;
			dp[i][j][1]=max(f(i,j-1,0)+dist(i,j),f(i,j-1,1)+dist(j,j-1));
			if (len==n){
				ans=max(ans,dp[i][j][0]);
				ans=max(ans,dp[i][j][1]);
			}
		//	cout<<i<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<endl;
		}
	}
	printf("%.13lf\n",ans);
	return 0;
}
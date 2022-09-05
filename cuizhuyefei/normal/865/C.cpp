#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> vec;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 55;
int n,R,f[N],s[N],p[N];
double dp[N][5005];
bool check(double det) {
//	rep(i,0,n) rep(j,0,5000) dp[i][j]=det;
	rep(i,0,R) dp[n][i]=0; rep(i,R+1,5000) dp[n][i]=det;
	per(i,n-1,0) rep(j,0,100*i)
		if (j>R) dp[i][j]=det; //left
		else {
			dp[i][j]=min(det,0.01*p[i+1]*(dp[i+1][j+f[i+1]]+f[i+1])+0.01*(100-p[i+1])*(dp[i+1][j+s[i+1]]+s[i+1]));
		}
	return dp[0][0]<det;
}
int main() {
	read(n); read(R);
	rep(i,1,n) read(f[i]),read(s[i]),read(p[i]);
	double l=0,r=2e9;
	rep(k,1,66) {
		double mid=(l+r)/2;
		if (check(mid)) r=mid; else l=mid;
	}
	printf("%.8lf",l);
	return 0;
}
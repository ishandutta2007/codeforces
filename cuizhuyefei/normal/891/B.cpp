#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define rep(i,a,b) for (int i=a; i<=b; i++)
#define per(i,a,b) for (int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline int max(int a, int b) {return a>b ? a : b;}
inline int min(int a, int b) {return a<b ? a : b;}
const int N = 30;
int n,a[N],b[N];
pair<int,int> s[N];

int main() {
	read(n); rep(i,1,n) read(a[i]),s[i]=pair<int,int>(a[i],i);
	sort(s+1,s+n+1);
	rep(i,1,n) b[s[i].second]=s[(i==1)?n:i-1].first;
	rep(i,1,n) printf("%d ",b[i]);
	return 0;
}
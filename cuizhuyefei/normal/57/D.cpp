#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 1020;
int n,m; char s[N][N];
int cnt1[N],cnt2[N],tot,pos1[N],pos2[N];
ll ans;
int Abs(int x) {return x>0?x:-x;}
int main() { //freopen("1.in","r",stdin);
	read(n); read(m); rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,m) cnt1[i]+=s[i][j]=='.',cnt2[j]+=s[i][j]=='.',tot+=s[i][j]=='.';
	rep(i,1,n) rep(j,1,m) if (s[i][j]=='X') pos1[i]=j,pos2[j]=i;
	rep(i,1,n) rep(j,1,n) ans+=1LL*Abs(i-j)*cnt1[i]*cnt1[j];
	rep(i,1,m) rep(j,1,m) ans+=1LL*Abs(i-j)*cnt2[i]*cnt2[j];
	rep(i,1,n) if (pos1[i]) rep(j,i,n) 
		if (j==i||pos1[j]>=pos1[j-1]) {
			ans+=4LL*(pos1[i]-1)*(m-pos1[j]);
		}
		else break;
	rep(i,1,n) if (pos1[i]) per(j,i-1,1)
		if (pos1[j]>=pos1[j+1]) {
			ans+=4LL*(pos1[i]-1)*(m-pos1[j]);
		}
		else break;
	rep(i,1,m) if (pos2[i]) rep(j,i,m)
		if (j==i||pos2[j]>=pos2[j-1]) {
			ans+=4LL*(pos2[i]-1)*(n-pos2[j]);
		}
		else break;
	rep(i,1,m) if (pos2[i]) per(j,i-1,1)
		if (pos2[j]>=pos2[j+1]) {
			ans+=4LL*(pos2[i]-1)*(n-pos2[j]);
		}
		else break;
	printf("%.12lf",1.0*ans/tot/tot);
	return 0;
}
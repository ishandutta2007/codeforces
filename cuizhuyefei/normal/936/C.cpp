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
const int N = 6003;
int n;
char s1[N],s2[N],t[N];
int m,x[N],buc[N];
int main() {
	read(n); scanf("%s%s",s1+1,s2+1);
	rep(i,1,n) {buc[s1[i]]++; buc[s2[i]]--;}
	rep(i,0,N-1) if (buc[i]!=0) {puts("-1"); return 0;}
	rep(i,1,n) rep(j,1,n) if (s2[i]==s1[j]) {
		x[++m]=n-j; x[++m]=1; x[++m]=n;
		memcpy(t,s1,sizeof(s1));
		rep(k,1,j-1) s1[k]=t[j-k];
		rep(k,j,n-1) s1[k]=t[k+1];
		s1[n]=t[j];
		break;
	}
	printf("%d\n",m);
	rep(i,1,m) printf("%d ",x[i]);
	return 0;
}
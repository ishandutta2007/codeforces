#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 1005000;
int sum(int *a, int n){int res=0;rep(i,1,n)res+=a[i];return res;}
const int o=500000;
int tp,a[N],b[N],va[N],vb[N],c[N],d[N],vc[N],vd[N],n=o,m=o;
char s[N];Vi ans1,ans2;
int main() {//freopen("1.in","r",stdin);
	scanf("%s",s+1);int l=strlen(s+1);tp^=s[1]=='a';
	rep(i,1,l){
		int j;for(j=i;j<=l;j++)if(s[j]!=s[i])break;
		a[++n]=j-i;i=j-1;//[i,j-1]
	}
	scanf("%s",s+1);l=strlen(s+1);tp^=s[1]=='a';
	rep(i,1,l){
		int j;for(j=i;j<=l;j++)if(s[j]!=s[i])break;
		b[++m]=j-i;i=j-1;//[i,j-1]
	}
	int *A=a+o,*B=b+o,*VA=va+o,*VB=vb+o;n-=o;m-=o;int i=n,j=m;
	VA[1]=0;VB[1]=tp;rep(i,2,n)VA[i]=VA[i-1]^1;rep(i,2,m)VB[i]=VB[i-1]^1;
	while(i>1||j>1){
		//gettrans
		int a,b;
		if(tp==0){
			int n=i,m=j;
			if(i>=j+3){a=(n-m+2)/2;b=1;if(a%2==1&&a+1<=n)a++;if(a%2==1)a--;}
			else if(j>=i+3){a=1;b=(m-n+2)/2;if(b%2==1&&b+1<=m)b++;if(b%2==1)b--;}
			else if(i>j)a=2,b=1;else a=1,b=2;
		}
		else{
			int n=i,m=j;
			if(i>=j+3){a=(n-m+2)/2;b=1;if(a%2==0&&a+1<=n)a++;if(a%2==0)a--;}
			else if(j>=i+3){a=1;b=(m-n+2)/2;if(b%2==0&&b+1<=m)b++;if(b%2==0)b--;}
			else {a=1;b=1;}
		}
		if(tp==0&&i==1&&(j==5||j%4==2))a=0,b=3;
		if(tp==0&&(i==5||i%4==2)&&j==1)a=3,b=0;
		if(tp==0&&i==1&&j==2)a=0,b=1;
		if(tp==0&&i==2&&j==1)a=1,b=0;
		ans1.pb(sum(A,a));ans2.pb(sum(B,b));
	//	printf("%d %d %d --> %d %d\n",tp,i,j,a,b);
		
		rep(i,1,a)c[i]=A[i],vc[i]=VA[i];rep(i,1,b)d[i]=B[i],vd[i]=VB[i];
		VA+=a;A+=a;VB+=b;B+=b;n-=a;m-=b;
		per(i,b,1)if(n&&VA[1]==vd[i])A[1]+=d[i];else A--,VA--,n++,A[1]=d[i],VA[1]=vd[i];
		per(i,a,1)if(m&&VB[1]==vc[i])B[1]+=c[i];else B--,VB--,m++,B[1]=c[i],VB[1]=vc[i];
		tp=VA[1]^VB[1];i=n;j=m;
	}
	int n=SZ(ans1);printf("%d\n",n);
	rep(i,0,n-1)printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}
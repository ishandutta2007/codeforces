#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
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
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 1020;
int n,a[N],b[N],nxt[N],l;char s[N][N];
inline void draw(){
//	printf("QAQ ");rep(i,1,n)printf("%d ",nxt[i]);puts("");
	rep(i,1,n)if(a[i]&&nxt[i]&&i!=nxt[i])//WA
		if(i>nxt[i])s[l][i]=s[l][nxt[i]]='\\';//WA
		else s[l][i]=s[l][nxt[i]]='/';
	memset(b,0,sizeof(b));rep(i,1,n)if(a[i])b[nxt[i]]=a[i];
	rep(i,1,n)a[i]=b[i];memset(nxt,0,sizeof(nxt));l--;
}
int main() {
	read(n);rep(i,1,n)read(a[i]);rep(i,1,n)rep(j,1,n)s[i][j]='.';
	bool bo=1;rep(i,1,n)bo&=a[i]==i;
	if(bo){printf("%d\n",n);rep(i,1,n){rep(j,1,n)printf(".");puts("");}return 0;}
	int p=0;rep(i,1,n)if(a[i]==n)p=i;
	rep(i,1,p-1)nxt[i]=i;rep(i,p+1,n)nxt[i]=i-1;l=n;draw();
	while(l>1){
	//	rep(i,1,n)printf("%d ",a[i]);puts("");
		if(!a[1]){
			int i;for(i=2;i<=n;i++)if(a[i]!=i-1)break;
			if(i>n){rep(j,1,n)nxt[j]=j;draw();}
			else{
				int p;for(p=1;p<=n;p++)if(a[p]==i-1)break;
				rep(j,1,n)nxt[j]=j;rep(j,2,i-1)nxt[j]=j-1;
				nxt[p]=i-1;rep(j,p+1,n)nxt[j]=j-1;draw();
			}
		}else{
			int i;for(i=n-1;i>=1;i--)if(a[i]!=i)break;
			if(i<1){rep(j,1,n)nxt[j]=j;draw();}
			else{
				int p;for(p=1;p<=n;p++)if(a[p]==i)break;
				rep(j,1,n)nxt[j]=j;rep(j,i+1,n-1)nxt[j]=j+1;
				nxt[p]=i+1;rep(j,1,p-1)nxt[j]=j+1;draw();
			}
		}
	}
	rep(i,1,n)nxt[i]=a[i];draw();
	printf("%d\n",n-1);rep(i,1,n){rep(j,1,n)printf("%c",s[i][j]);puts("");}
	return 0;
}
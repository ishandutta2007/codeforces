#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; char ch=G;
	for (;!isdigit(ch);ch=G);
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return x;
}
#undef G
typedef long long ll;

int n,m,q;
char s[1010][1010];
bool mrk[1010][1010];
int t[1010][1010];
int gethash(int x,int y){
	return (x-1)*m+y;
}
void getid(int h,int &x,int &y){
	x=(h-1)/m+1,y=(h-1)%m+1;
}
int que[1000010],hd,tl;
int main(){
	n=read(),m=read(),q=read();
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	if (n==1&&m==1){
		while (q--) putchar(s[1][1]),putchar('\n');
		return 0;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			if (i>1&&s[i-1][j]==s[i][j]) continue;
			if (i<n&&s[i+1][j]==s[i][j]) continue;
			if (j>1&&s[i][j-1]==s[i][j]) continue;
			if (j<m&&s[i][j+1]==s[i][j]) continue;
			mrk[i][j]=1;
		}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			if (!mrk[i][j]) que[++tl]=gethash(i,j);
	while (hd<tl){
		int u=que[++hd],i,j; getid(u,i,j);
		if (i>1&&mrk[i-1][j]){
			mrk[i-1][j]=0; t[i-1][j]=t[i][j]+1;
			que[++tl]=gethash(i-1,j);
		}
		if (i<n&&mrk[i+1][j]){
			mrk[i+1][j]=0; t[i+1][j]=t[i][j]+1;
			que[++tl]=gethash(i+1,j);
		}
		if (j>1&&mrk[i][j-1]){
			mrk[i][j-1]=0; t[i][j-1]=t[i][j]+1;
			que[++tl]=gethash(i,j-1);
		}
		if (j<m&&mrk[i][j+1]){
			mrk[i][j+1]=0; t[i][j+1]=t[i][j]+1;
			que[++tl]=gethash(i,j+1);
		}
	}
	while (q--){
		int x=read(),y=read(); ll val; scanf("%I64d",&val);
		if (mrk[x][y]){
			putchar(s[x][y]); putchar('\n');
			continue;
		}
		if (val<=t[x][y]){
			putchar(s[x][y]); putchar('\n');
			continue;
		}
		val=(val-t[x][y])&1;
		putchar(s[x][y]^val); putchar('\n');
	}
	return 0;
}
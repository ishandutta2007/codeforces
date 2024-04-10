#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G

int ans[310][310];
int a[310][310];
int n,m;
void init(){
	
}
void solve(){
	n=read(); m=read();
	bool flg=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			ans[i][j]=0;
			if (i>1) ans[i][j]++;
			if (i<n) ans[i][j]++;
			if (j>1) ans[i][j]++;
			if (j<m) ans[i][j]++;
			if (ans[i][j]<read()) flg=0;
		}
	if(!flg) return puts("NO"),void();
	puts("YES");
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			printf("%d%c",ans[i][j]," \n"[j==m]); 
}
int main()
{
	for (int T=read();T--;) init(),solve();
}
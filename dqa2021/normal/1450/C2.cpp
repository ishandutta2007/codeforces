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

int n,m;
char s[310][310];
void solve(){
	n=read();
	for (int i=1;i<=n;i++) scanf("%s",s[i]+1);
	m=0;
	for(int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			m+=s[i][j]!='.';
	for (int a=0;a<3;a++)
		for (int b=0;b<3;b++)
			if (a^b){
				int tot=0;
				for (int i=1;i<=n;i++)
					for (int j=1;j<=n;j++){
						int c=(i+j)%3;
						if (c==a&&s[i][j]=='O') tot++;
						if (c==b&&s[i][j]=='X') tot++;
					}
				if (tot*3>m) continue;
				for (int i=1;i<=n;i++)
					for (int j=1;j<=n;j++){
						int c=(i+j)%3;
						if (c==a&&s[i][j]=='O') s[i][j]='X';
						if (c==b&&s[i][j]=='X') s[i][j]='O';
					}
				for (int i=1;i<=n;i++) puts(s[i]+1);
				return;
			}
	puts("ERR");
}
int main()
{
	for (int T=read();T--;) solve();
}
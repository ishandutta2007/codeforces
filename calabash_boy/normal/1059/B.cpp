#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
template<class T>inline void print(T x){if(x/10!=0)print(x/10);putchar(x%10+'0');}
template<class T>inline void writeln(T x){if(x<0)putchar('-');x=abs(x);print(x);putchar('\n');}
template<class T>inline void write(T x){if(x<0)putchar('-');x=abs(x);print(x);}
/*================Header Template==============*/
int n,m,vis[1005][1005];
char s[1005][1005];
const int step[8][2]={{0,1},{1,0},{-1,0},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};
int main() {
	read(n),read(m);
	for(int i=1;i<=n;++i)
		scanf("%s",s[i]+1);
	for(int i=2;i<n;++i)
		for(int j=2;j<m;++j) {
			int l=1;
			for(int k=0;k<8&&l;++k) {
				int nx=i+step[k][0],ny=j+step[k][1];
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m) {
					if(s[nx][ny]=='.') {
						l=0;
						break;
					}
				}
			}
			if(l)
				for(int k=0;k<8&&l;++k) {
					int nx=i+step[k][0],ny=j+step[k][1];
					if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
						vis[nx][ny]=1;
				}
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			if(s[i][j]=='#'&&!vis[i][j])
				exit(0*puts("NO"));
	puts("YES");
}
#include<cstdio>
#include<iostream>
using namespace std;
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f;
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48);
}
const int o=101;
int n,m,st[o],cnt,vis[o],ans;string s[o];
void dfs(int nw){if(nw>cnt) return;if(st[nw]-vis[st[nw]]) cout<<s[st[nw]],dfs(nw+1),cout<<s[vis[st[nw]]];else cout<<s[st[nw]];}
int main(){
	read(n);read(m);
	for(int i=1;i<=n;++i) cin>>s[i];
	for(int i=1;i<n;++i){
		if(vis[i]) continue;
		for(int j=i+1;j<=n;++j)
			if(!vis[j]){
				bool flg=0;
				for(int k=0;k<m;++k) if(s[i][k]-s[j][m-k-1]){flg=1;break;}
				if(!flg){vis[j]=i;vis[i]=j;st[++cnt]=i;ans+=2;break;}
			}
	}
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			bool flg=0;
			for(int j=0;j<m;++j) if(s[i][j]-s[i][m-j-1]){flg=1;break;}
			if(!flg){st[++cnt]=vis[i]=i;++ans;break;}
		}
	write(ans*m);putchar('\n');dfs(1);
	return 0;
}
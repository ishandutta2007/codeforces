#include<bits/stdc++.h>
#define ll long long
#define fo(i,j,k) for(int i=(j),end_i=(k);i<=end_i;i++)
#define fd(i,j,k) for(int i=(j),end_i=(k);i>=end_i;i--)
using namespace std;
template<class T>
void read(T &x){
	x=0;
	char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
}
char s[505][505];
int a[505][505],b[505][505],c[505][505];
int main(){
	int n,m,i,j,ans=0;
	read(n);read(m);
	for(i=1;i<=n;++i)scanf("%s",s[i]+1);
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(s[i][j]=='W')a[i][j]=0;
			else a[i][j]=1;
		}
	}
	for(i=n;i>=1;--i){
		for(j=m;j>=1;--j){
			b[i][j]=a[i+1][j]^a[i][j+1]^a[i+1][j+1]^a[i][j];
		}
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j)ans+=b[i][j];
	}
	bool flg=1;
	if(b[n][m]){
		for(i=1;i<n;++i){
			for(j=1;j<m;++j)if(b[i][m]&&b[n][j]&&b[i][j]&&flg){
				--ans;
				flg=0;
				break;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
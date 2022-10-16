#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 1000000000
using namespace std;
int w,n,m,a[100005],cnt[4096];
int v0[4096],v1[4096],f[4096][4096];
char s[15];
int main(){
	cin>>w>>n>>m;
	for (int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
	for (int i=0;i<(1<<w);i++){
		for (int j=0;j<(1<<w);j++){
			int k=j;
			for (int l=0;l<w;l++)
				if ((i&(1<<l))&&(k&(1<<l)))k^=(1<<l);
			f[i][k]+=cnt[j];
		}
	}
	for (int i=1;i<=m;i++){
		scanf("%s",s);
		reverse(s,s+w);
		memset(v0,0,sizeof(v0));
		memset(v1,0,sizeof(v1));
		for (int j=0;j<w;j++){
			for (int k=(1<<j);k<(1<<(j+1));k++)v0[k]=v0[k-(1<<j)],v1[k]=v1[k-(1<<j)];
			for (int k=0;k<(1<<(j+1));k++){
				if (k&(1<<j)){
					if (s[j]=='A'){
						v0[k]=v0[k];
						v1[k]=v1[k];
					}
					if (s[j]=='O'){
						v0[k]=-inf;
						v1[k]=-inf;
					}
					if (s[j]=='X'){
						v0[k]=v0[k];
						v1[k]=v1[k]+(1<<j);
					}
					if (s[j]=='a'){
						v0[k]=v0[k];
						v1[k]=v1[k]+(1<<j);
					}
					if (s[j]=='o'){
						v0[k]=v0[k]+(1<<j);
						v1[k]=v1[k];
					}
					if (s[j]=='x'){
						v0[k]=v0[k];
						v1[k]=v1[k];
					}
				}
				else{
					if (s[j]=='A'){
						v0[k]=v0[k]+(1<<j);
						v1[k]=v1[k];
					}
					if (s[j]=='O'){
						v0[k]=v0[k];
						v1[k]=v1[k];
					}
					if (s[j]=='X'){
						v0[k]=v0[k];
						v1[k]=v1[k];
					}
					if (s[j]=='a'){
						v0[k]=-inf;
						v1[k]=-inf;
					}
					if (s[j]=='o'){
						v0[k]=v0[k];
						v1[k]=v1[k]+(1<<j);
					}
					if (s[j]=='x'){
						v0[k]=v0[k];
						v1[k]=v1[k]+(1<<j);
					}
				}
			}
		}
		int ans=0;
		for (int j=0;j<(1<<w);j++)
			if (v0[j]>=0&&v1[j]>=0)ans+=cnt[j]*f[v0[j]][v1[j]];
		cout<<ans<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
char c[4100];
int n,m,ans;
int a[16400],b[16400],f[33000];
int F(int x){
	return f[x]==x?x:f[x]=F(f[x]);
}
void merge(int a,int b){
	a=F(a),b=F(b);
	if(a!=b)ans--,f[a]=b;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		swap(a,b);
		scanf("%s",c+1);
		for(int j=1;j<=m/4;j++){
			int num=('0'<=c[j]&&c[j]<='9')?c[j]-'0':c[j]-'A'+10;
			for(int k=j*4;k>(j-1)*4;k--){
				b[k]=num&1,num>>=1;
				if(b[k]==1)ans++;
			}
		}
		for(int j=1;j<=m;j++)if(b[j]==1){
			f[j+m]=j+m;
			if(b[j-1]==1)merge(j-1+m,j+m);
			if(a[j]==1)merge(j,j+m);
		}
		for(int j=1;j<=m;j++)f[j]=f[j+m]-m;
	}
	printf("%d",ans);
}
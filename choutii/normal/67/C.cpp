#include<bits/stdc++.h>
#define FO(x) {freopen(#x".in","r",stdin);\
				freopen(#x".out","w",stdout);}
#define fir first
#define sec second
using namespace std;
typedef long long ll;
template<typename T>inline bool cmin(T &a,const T &b){ return a>b?a=b,1:0;}
template<typename T>inline bool cmax(T &a,const T &b){ return a<b?a=b,1:0;}
int a,b,c,d,n,m,x[4567][26],y[4567][26],f[4567][4567];
char s[4567],t[4567];
int main(){
	int i,j;
	scanf("%d%d%d%d%s%s",&a,&b,&c,&d,s,t);
	n=strlen(s); m=strlen(t);
	for(i=1;i<=n;i++){
		for(j=0;j<26;j++)x[i][j]=x[i-1][j];
		if(i>1)x[i][s[i-2]-'a']=i-1;
	}
	for(i=1;i<=m;i++){
		for(j=0;j<26;j++)y[i][j]=y[i-1][j];
		if(i>1)y[i][t[i-2]-'a']=i-1;
	}
	for(i=0;i<=n;i++)
		for(j=0;j<=m;j++)
			if(i||j){
				f[i][j]=1e9;
				if(j)cmin(f[i][j],f[i][j-1]+a);
				if(i)cmin(f[i][j],f[i-1][j]+b);
				if(i&&j)cmin(f[i][j],f[i-1][j-1]+c*(s[i-1]!=t[j-1]));
				int u=x[i][t[j-1]-'a'],v=y[j][s[i-1]-'a'];
				if(u&&v)cmin(f[i][j],f[u-1][v-1]+d+(i-u-1)*b+(j-v-1)*a);
			}
	cout<<f[n][m];
	return 0;
}
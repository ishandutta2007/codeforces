#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=200010;
int i,j,k,n,m,T,w[maxn][21];
int main(){
	cin>>T;
	for(i=1;i<maxn;i++){
		for(j=0;j<=20;j++){
			w[i][j]=w[i-1][j]+(i&(1<<j)?1:0);
		}
	}
	while(T--){
		int l,r,ans=0;
		l=read();r=read();
		for(i=0;i<=20;i++)ans=max(ans,w[r][i]-w[l-1][i]);
		printf("%d\n",r-l+1-ans);
	}
	return 0;
}
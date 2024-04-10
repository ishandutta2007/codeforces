#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T,a[111][111];
int main(){
	T=read();
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)a[i][j]=read();
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)printf("%d ",(a[i][j]%2==(i+j)%2)?a[i][j]:a[i][j]+1);
			puts("");
		}
	}
	return 0;
}
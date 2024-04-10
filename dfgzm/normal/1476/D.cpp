#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=300010;
int i,j,k,n,m,T,l[maxn][2],r[maxn][2];
string S;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cin>>S;
		int ans=1e9;
		for(i=2;i<=n+1;i++)
			for(j=0;j<=1;j++)
				if((S[i-2]=='L')^(j==1))l[i][j]=l[i-1][j^1]+1;
		for(i=n;i>=1;i--)
			for(j=0;j<=1;j++)
				if((S[i-1]=='R')^(j==1))r[i][j]=r[i+1][j^1]+1;
		for(i=1;i<=n+1;i++){
			printf("%d ",l[i][0]+r[i][0]+1);
		}puts("");
		for(i=1;i<=n+2;i++)l[i][0]=l[i][1]=r[i][0]=r[i][1]=0;
	}
	return 0;
}
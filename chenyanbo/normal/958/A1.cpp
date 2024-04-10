#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

int a[15][15],b[15][15],c[15][15],n,fl; //bool

inline void solve()
{
	fl=1;
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)if(c[i][j]!=b[i][j]){
		fl=0;
		break;
	}
	
	if(fl){
		cout<<"Yes";
		exit(0);
//		return 0;
	}
	
	fl=1;
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)if(c[i][j]!=b[i][j]){
		fl=0;
		break;
	}
	
	if(fl){
		cout<<"Yes";
		exit(0);  //
//		return 0; ///
	}
	
	fl=1;
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)if(c[n-i+1][j]!=b[i][j]){
		fl=0;
		break;
	}
	
	if(fl){
		cout<<"Yes";
		exit(0);
//		return 0;
	}
	
	fl=1;
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)if(c[n-i+1][n-j+1]!=b[i][j]){
		fl=0;
		break;
	}
	
	if(fl){
		cout<<"Yes";
		exit(0);
		return;
	}
	
	fl=1;
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)if(c[i][n-j+1]!=b[i][j]){
		fl=0;
		break;
	}
	
	if(fl){
		cout<<"Yes";
		exit(0);
//		return 0;
	}
	
}
char s[5005];
int main()
{
	n=read();
	for(int i=1; i<=n; ++i){
		scanf("%s",s+1);
		for(int j=1; j<=n; ++j)c[i][j]=(s[j]=='X');
	} 
	for(int i=1; i<=n; ++i){
		scanf("%s",s+1);
		for(int j=1; j<=n; ++j)b[i][j]=(s[j]=='X');
	}
	
	solve();//_ ,
	
	//zhijie ???
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)a[i][j]=c[n-j+1][i];
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)c[i][j]=a[i][j]; //memcpy
	
	for(int i=1; i<=3; ++i){
		solve();
		for(int i=1; i<=n; ++i)
	for(int j=1; j<=n; ++j)a[i][j]=c[n-j+1][i];
	memcpy(c,a,sizeof(a)); // /
	memcpy(a,a,sizeof a);
	memcpy(c,a,sizeof a); //<  > ==
}//link cut  next prec  prev //_ top


//make
//gen
	
	puts("No");
	
}
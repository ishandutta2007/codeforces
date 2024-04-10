#include<bits/stdc++.h>
using namespace std;
char a[105][105];
int b[106],fk[4];
bool bo[105];
int main(){
	int n,m,k,i,j,s;
	bool f1=0,f2=0,fa=0,fb=0;
	scanf("%d%d%d",&n,&m,&k);
	if(m==1){
		puts("Second");
		return 0;
	}
	for(i=1;i<=n;++i){
		scanf("%s",a[i]+1);
		bool ff=1;
		for(j=2;j<=m;++j){
			if(a[i][j]!=a[i][1]){
				ff=0;
				break;
			}
		}
		bo[i]=ff;
	}
	for(i=1;i<=n;++i){
		for(j=1;j<=m;++j){
			if(a[i][j]=='G')a[i][j]=1;
			else if(a[i][j]=='R')a[i][j]=2;
			else a[i][j]=0;
		}
	}
	for(i=1;i<=n;++i){
		if(bo[i])continue;
		fk[1]=fk[2]=0;
		for(j=1;j<=m;++j){
			if(a[i][j])++fk[a[i][j]];
		}
		if(fk[1]&&fk[2])continue;
		if(!fk[1])f2=1;
		if(!fk[2])f1=1;
	}
	if(f1&&f2)puts("Draw");
	else if(f1)puts("First");
	else if(f2)puts("Second");
	else{
		for(i=1;i<=n;++i){
			int x=0,y=0;
			if(bo[i])continue;
			for(j=1;j<=m;++j){
				if(a[i][j]){
					if(!x)x=j;
					else y=j;
				}
			}
			if(x&&y)b[i]=y-x-1;
			else b[i]=0;
		}
		++k;
		for(i=6;i>=0;--i){
			s=0;
			for(j=1;j<=n;++j){
				if(b[j]&(1<<i))++s;
			}
			if(s%k){
				puts("First");
				return 0;
			}
		}
		puts("Second");
	}
	return 0;
}
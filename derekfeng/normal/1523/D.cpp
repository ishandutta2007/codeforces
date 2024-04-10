#include<bits/stdc++.h>
using namespace std;
mt19937 rng(114514);
char c[200004][66];
int n,m,p,sum[32800];
int res;
char ans[66];
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=0;i<m;i++)ans[i]='0';
	for(int i=0;i<n;i++)scanf("%s",c[i]);
	for(int i=0;i<20;i++){
		int x=rng()%n;
		vector<int>t;
		for(int j=0;j<m;j++)if(c[x][j]=='1')t.push_back(j);
		p=t.size();
		memset(sum,0,sizeof(sum));
		for(int j=0;j<n;j++){
			int mask=0;
			for(int k=0;k<p;k++)if(c[j][t[k]]=='1')mask|=(1<<k);
			sum[mask]++;
		}
		for(int j=0;j<p;j++)for(int k=0;k<(1<<p);k++)
			if(!(k&(1<<j)))sum[k]+=sum[k|(1<<j)];
		for(int k=1;k<(1<<p);k++)if(sum[k]>=(n+1)/2&&__builtin_popcount(k)>res){
			res=__builtin_popcount(k);
			for(int j=0;j<m;j++)ans[j]='0';
			for(int j=0;j<p;j++)if((1<<j)&k)ans[t[j]]='1';
		}
	}
	printf("%s",ans);
}
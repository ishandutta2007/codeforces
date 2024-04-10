#include<bits/stdc++.h>
using namespace std;
int n,m,T,ans,pos,num[25],a[12],p[10004];
char c[12][10004];
int val[11][1025][1025],msk[10004];
vector<int>ret,v[25];
void sol(){
	ans=0,pos=0;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++)scanf("%s",&c[i]);
	for(int i=0;i<m;i++){
		msk[i]=0;
		for(int j=0;j<n;j++)if(c[j][i]=='1')
			msk[i]|=(1<<j);
	}
	for(int i=0;i<(1<<n);i++){
		int tmp=0;
		for(int j=0;j<n;j++){
			if((i>>j)&1)tmp+=-a[j];
			else tmp+=a[j];
		}
		memset(num,0,sizeof(num));
		for(int j=0;j<m;j++){
			num[val[n][msk[j]][i]+10]++;
		}
		int N=m;
		for(int i=10;i>=-10;i--){
			int x=num[i+10];
			while(x>0)tmp+=i*N,x--,N--;
		}
		if(tmp>ans)ans=tmp,pos=i;
	}
	for(int i=0;i<25;i++)v[i].clear();
	for(int i=0;i<m;i++)
		v[val[n][msk[i]][pos]+10].push_back(i);
	int N=m;
	for(int i=10;i>=-10;i--){
		while(!v[i+10].empty()){
			int u=v[i+10].back();v[i+10].pop_back();
			p[u]=N,N--;
		}
	}
	for(int i=0;i<m;i++)printf("%d ",p[i]);puts("");
}
int main(){
	for(int i=1;i<=10;i++)for(int j=0;j<(1<<i);j++)for(int k=0;k<(1<<i);k++){
		val[i][j][k]=0;
		for(int l=0;l<i;l++)if((j>>l)&1){
			if((k>>l)&1)val[i][j][k]++;
			else val[i][j][k]--;
		}
	}
	scanf("%d",&T);
	while(T--)sol();
}
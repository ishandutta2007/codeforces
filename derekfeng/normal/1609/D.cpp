#include<bits/stdc++.h>
using namespace std;
int n,d,sum,u[1004],v[1004];
int f[1004],sz[1004],SZ;
int F(int x){
	return x==f[x]?x:f[x]=F(f[x]);
}
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=d;i++)scanf("%d%d",&u[i],&v[i]);
	for(int i=1;i<=d;i++){
		for(int j=1;j<=n;j++)f[j]=j,sz[j]=1;
		SZ=0;
		for(int j=1;j<=i;j++){
			if(F(u[j])==F(v[j]))SZ++;
			else sz[F(v[j])]+=sz[F(u[j])],f[F(u[j])]=F(v[j]);
		}
		vector<int>v;
		for(int j=1;j<=n;j++)if(F(j)==j)v.push_back(sz[j]);
		sort(v.begin(),v.end(),greater<int>());
		sum=0;
		for(int j=0;j<v.size()&&j<=SZ;j++)sum+=v[j];
		printf("%d\n",sum-1);
	}
}
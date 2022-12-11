#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define LL long long
using namespace std;
const int N=2e5+50;
int n,f[2][N],s[2][N];LL ans;
int find(int *f,int x){return f[x]==x?x:f[x]=find(f,f[x]);}
void add(int *f,int *s,int x,int y){
	x=find(f,x);y=find(f,y);
	if(x!=y)f[x]=y,s[y]+=s[x];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)f[0][i]=f[1][i]=i,s[0][i]=s[1][i]=1;
	for(int i=1,x,y,z;i<n;i++){
		scanf("%d%d%d",&x,&y,&z);
		add(f[z],s[z],x,y);
	}
	for(int i=1;i<=n;i++)ans+=1ll*s[0][find(f[0],i)]*s[1][find(f[1],i)]-1;
	printf("%I64d",ans);
	return 0;
}
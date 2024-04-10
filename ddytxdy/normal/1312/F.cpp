#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+50,M=1e7;
int t,n,x,y,z,f[M][3],ll,rr,dat[N],sum;bool vis[N];LL a[N];
map<LL,int>mp;
int mex(int x,int y,int z){
	vis[x]=vis[y]=vis[z]=1;int ret=0;
	for(int i=0;;i++)if(!vis[i]){ret=i;break;}
	vis[x]=vis[y]=vis[z]=0;return ret;
}
LL read(){
	LL x=0;int c;
	while(!isdigit(c=getchar()));
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
int get(LL a,int op){
	return a<=rr?f[a][op]:f[(a-ll)%(rr-ll)+ll][op];
}
int solve(){
	scanf("%d%d%d%d",&n,&x,&y,&z);mp.clear();sum=0;
	for(int i=1;;i++){
		f[i][0]=mex(f[max(0,i-x)][0],f[max(0,i-y)][1],f[max(0,i-z)][2]);
		f[i][1]=mex(f[max(0,i-x)][0],f[max(0,i-z)][2],10);
		f[i][2]=mex(f[max(0,i-x)][0],f[max(0,i-y)][1],10);
		LL dat=0,now=1;dat=f[i-1][0];
		for(int j=2;j<=x;j++)now*=4,dat+=f[max(i-j,0)][0]*now;
		for(int j=1;j<=y;j++)now*=4,dat+=f[max(i-j,0)][1]*now;
		for(int j=1;j<=z;j++)now*=4,dat+=f[max(i-j,0)][2]*now;
		if(mp[dat]){ll=mp[dat],rr=i;break;}mp[dat]=i;
	}
	for(int i=1;i<=n;i++)dat[i]=get(a[i]=read(),0),sum^=dat[i];
	if(!sum)return 0;int num=0;
	for(int i=1;i<=n;i++){
		if(!(sum^dat[i]^get(max(0ll,a[i]-x),0)))num++;
		if(!(sum^dat[i]^get(max(0ll,a[i]-y),1)))num++;
		if(!(sum^dat[i]^get(max(0ll,a[i]-z),2)))num++;
	}
	return num;
}
int main(){
	scanf("%d",&t);
	while(t--)cout<<solve()<<endl;
}
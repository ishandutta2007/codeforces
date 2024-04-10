#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int pw(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		y>>=1;
	}
	return res;
}
const int N=1000;
int n;
char s[N+5];
int fa[4*N+3];
int id(int x,int y,int z){return 2*((x-1)*n+y)-z;}
int root(int p){return fa[p]==p?p:fa[p]=root(fa[p]);}
void merge(int p,int q){fa[root(p)]=root(q);}
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=4*n+2;j++)fa[j]=j;
		merge(id(1,1,1),4*n+1);merge(id(1,1,0),4*n+2);
		for(int j=1;j<=n/2;j++)
			merge(id(1,j,0),id(1,n+1-j,0)),merge(id(1,j,1),id(1,n+1-j,1));
		for(int j=1;j<i;j++)
			merge(id(2,j,0),4*n+1),merge(id(2,j,1),4*n+2);
		merge(id(2,i,1),4*n+1);merge(id(2,i,0),4*n+2);
		for(int j=i;j<=(i-1+n)/2;j++)
			merge(id(2,j,0),id(2,n+i-j,0)),merge(id(2,j,1),id(2,n+i-j,1));
		for(int j=1;j<=n;j++)
			if(s[j]=='1')merge(id(1,j,0),id(2,j,1)),merge(id(1,j,1),id(2,j,0));
			else if(s[j]=='0')merge(id(1,j,0),id(2,j,0)),merge(id(1,j,1),id(2,j,1));
		bool ok=true;
		for(int j=1;j<4*n+2;j+=2)if(root(j)==root(j+1)){ok=false;break;}
		if(!ok)continue;
		int cnt=0;
		for(int j=1;j<=4*n+2;j++)cnt+=fa[j]==j;
		(ans+=pw(2,cnt/2-1))%=mod;
	}
	printf("%d",ans);
	return 0;
}
/*1
10110
*/
/*2
1?0???10
*/
/*3
1?????????????????????????????????????
*/
/*4
1
*/
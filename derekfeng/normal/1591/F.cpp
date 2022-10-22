#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int M=998244353,inf=1e9;
int n,sum[2];
stack<pii>sta[2];
void calc(int i,int x){
	int add=0;
	while(!sta[i].empty()){
		pii u=sta[i].top();
		if(u.fi<x)break;
		(sum[i]+=M-(ll)u.fi*u.se%M)%=M;
		sta[i].pop(),(add+=u.se)%=M;
	}
	(sum[i]+=(ll)x*add%M)%=M;
	sta[i].push({x,add});
}
int main(){
	scanf("%d",&n);
	sta[0].push({inf,1}),sta[1].push({inf,0});
	sum[0]=inf,sum[1]=0;
	for(int i=1;i<=n;i++){
		int x;scanf("%d",&x);
		calc(0,x),calc(1,x);
		int f0=sum[1],f1=sum[0];
		sta[0].push({inf,f0}),sta[1].push({inf,f1});
		(sum[0]+=(ll)inf*f0%M)%=M,(sum[1]+=(ll)inf*f1%M)%=M;
	}
	int num[2]={sta[0].top().se,sta[1].top().se};
	if(n&1)swap(num[0],num[1]);
	printf("%d",(num[0]-num[1]+M)%M);
}
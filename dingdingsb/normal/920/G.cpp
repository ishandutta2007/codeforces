#pragma optimize(2)
#include<bits/stdc++.h>
using namespace std;
int t,x,p,k,sum;
int len,s[30];
void dfs(int &ans,int now,int num,int MAX,int f){
	//x 
	if(now>len){
		ans+=MAX/num*f;
		return;
	}
	dfs(ans,now+1,num,MAX,f);
	dfs(ans,now+1,num*s[now],MAX,-f);
}
bool check(int mid){
	int tmp=0;dfs(tmp,1,1,mid,1);
	return sum+k<=tmp;
}
signed main(){
	scanf("%d",&t);
	while(t--){
		len=0;
		scanf("%d%d%d",&x,&p,&k);
		for(int i=2;i*i<=p;i++)
			if(p%i==0){
				s[++len]=i;
				while(p%i==0)
					p/=i;
			}
		if(p>1)
			s[++len]=p;
		sum=0;dfs(sum,1,1,x,1);
		int l,r;
		for(l=x,r=1e8;l<=r;){
			int mid=l+r>>1;
			check(mid)?r=mid-1:l=mid+1;
		}
		printf("%d\n",l);
	}
}
#include<bits/stdc++.h>
using namespace std;
int t;
int x,p,k;
int mu[1000005],pri[300005],tot;
bool f[1000005];
void init(){
	mu[1]=1;
	for(int i=2;i<=1e6;i++){
		if(!f[i])pri[++tot]=i,mu[i]=-1;
		for(int j=1;j<=tot&&pri[j]*i<=1e6;j++){
			f[pri[j]*i]=1;
			if(i%pri[j]==0){
				mu[pri[j]*i]=0;
				break;
			}
			mu[pri[j]*i]=-mu[i];
		}
	}
}
int qry(int x){
	int ans=0;
	for(int i=1;i*i<=p;i++)if(p%i==0){
		ans+=mu[i]*(x/i);
		if(p/i!=i)ans+=mu[p/i]*(x/(p/i));
	}
	return ans;
}
int main(){
	init();
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&x,&p,&k);
		int l=x,r=1e7;
		int tmp=qry(x);
		while(r>l+1){
			int mid=(l+r)>>1;
			if(qry(mid)-tmp>=k)r=mid;
			else l=mid;
		}
		printf("%d\n",r);
	}
}
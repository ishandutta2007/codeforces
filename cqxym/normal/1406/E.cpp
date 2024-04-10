#include<iostream>
#include<algorithm>
using namespace std;
#define R register int
#define N 100001
bool vis[N];
int prime[9592];
inline void GetAns(int l,int r,int&res){
	if(l>r){
		return;
	}
	int mid=l+r>>1,tem;
	for(R i=l;i<=mid;i++){
		printf("B %d\n",prime[i]);
		fflush(stdout);
		scanf("%d",&tem);
	}
	puts("A 1");
	fflush(stdout);
	scanf("%d",&tem);
	if(tem==r-mid+1){
		return GetAns(mid+1,r,res);
	}
	for(R i=l;i<=mid;i++){
		printf("A %d\n",prime[i]);
		fflush(stdout);
		scanf("%d",&tem);
		if(tem!=0){
			res*=prime[i];
			return;
		}
	}
}
int main(){
	int ct=0;
	for(R i=2;i!=N;i++){
		if(vis[i]==false){
			prime[ct]=i;
			ct++;
			for(R j=i<<1;j<N;j+=i){
				vis[j]=true;
			}
		}
	}
	int n,res=1,lt=-1,pct=0;
	scanf("%d",&n);
	for(R i=0;prime[i]*prime[i]<=n;i++){
		lt=i;
		int u=prime[i];
		while(u*prime[i]<=n){
			u*=prime[i];
		}
		int tem;
		printf("B %d\n",u);
		fflush(stdout);
		scanf("%d",&tem);
		printf("A %d\n",u);
		fflush(stdout);
		scanf("%d",&tem);
		pct+=2;
		while(tem==0){
			u/=prime[i];
			if(u==1){
				break;
			}
			printf("B %d\n",u);
			fflush(stdout);
			scanf("%d",&tem);
			printf("A %d\n",u);
			fflush(stdout);
			scanf("%d",&tem);
			pct+=2;
		}
		if(u>prime[i]){
			printf("B %d\n",prime[i]);
			fflush(stdout);
			scanf("%d",&tem);
			pct++;
		}
		res*=u;
	}
	int rt=std::upper_bound(prime,prime+ct,n)-prime;
	if(res==1){
		GetAns(lt+1,rt-1,res);
	}else{
		int tem;
		random_shuffle(prime+lt+1,prime+rt);
		for(R i=lt+1;i!=rt&&pct<9998;i++){
			if((long long)prime[i]*res<=n&&prime[i]!=0){
				printf("B %d\n",prime[i]);
				fflush(stdout);
				scanf("%d",&tem);
				printf("A %d\n",prime[i]);
				fflush(stdout);
				scanf("%d",&tem);
				if(tem!=0){
					res*=prime[i];
					break;
				}
				pct+=2;
			}
		}
	}
	printf("C %d",res);
	fflush(stdout);
	return 0;
}
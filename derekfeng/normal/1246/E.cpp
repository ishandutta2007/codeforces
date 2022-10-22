#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
bitset<2004>f[65536];
int n,K,a[16],b[16];
int main(){
	scanf("%d%d",&n,&K);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=1;i<(1<<n);i++){
		if(__builtin_popcount(i)==1){
			int x=__builtin_ctz(i);
			f[i].set(a[x]);
		}else{
			for(int j=0;j<n;j++)if((i>>j)&1)
				f[i]|=f[i^(1<<j)]<<a[j];
		}
		for(int j=2000/K;j;j--)if(f[i][j*K])f[i].set(j);
	}f[0][0]=1;
	if(!f[(1<<n)-1][1])return puts("NO"),0;
	puts("YES");vector<pii>ans;
	int cur=1,msk=(1<<n)-1;
	for(;;){
		if(!msk){
			priority_queue<pii>pq;
			for(int i=0;i<n;i++)pq.push({b[i],a[i]});
			while(pq.size()>1){
				auto [A,x]=pq.top();pq.pop();
				auto [B,y]=pq.top();pq.pop();
				printf("%d %d\n",x,y);
				int w=x+y;while(w%K==0)w/=K,A--;
				pq.push({A,w});
			}
			return 0;
		}
		while(cur*K<=2000&&f[msk][cur*K]){
			for(int i=0;i<n;i++)if((msk>>i)&1)b[i]++;cur*=K;
		}
		for(int i=0;i<n;i++)if((msk>>i)&1)
			if(cur>=a[i]&&f[msk^(1<<i)][cur-a[i]]){
				msk^=(1<<i),cur-=a[i];break;
			}
	}
}
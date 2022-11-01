#include<stdio.h>
#define R register int
bool vis[1000001];
int sum[1000001];
inline void Solve(){
	int n,c,x;
	scanf("%d%d",&n,&c);
	for(R i=1;i<=c;i++){
		vis[i]=false;
		sum[i]=0;
	}
	for(R i=0;i!=n;i++){
		scanf("%d",&x);
		vis[x]=true;
		sum[x]++;
	}
	for(R i=1;i<=c;i++){
		sum[i]+=sum[i-1];
	}
	for(R i=1;i<=c;i++){
		if(vis[i]==false){
			for(R j=1;j*i<=c;j++){
				if(vis[j]==true){
					int l=j*i,r=j*(i+1)-1;
					if(r>c){
						r=c;
					}
					if(sum[r]!=sum[l-1]){
						puts("No");
						return;
					}
				}
			}
		}
	}
	puts("Yes");
}
int main(){
	int t;
	scanf("%d",&t);
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
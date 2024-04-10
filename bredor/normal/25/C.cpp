//  228

#include <cstdio>
int mp[305][305];
int mn(int a,int b){
	return a<b?a:b;
}
int main(){
	int n;
	int k;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&mp[i][j]);
		}
	}
	scanf("%d",&k);
	int a,b,c;
	long long sum;
	while(k--){
		scanf("%d%d%d",&a,&b,&c);
		sum=0;
		if(mp[a][b]>c){
			mp[a][b]=mp[b][a]=c;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i==j){
						continue;
					}
					mp[i][j]=mp[j][i]=mn(mp[i][j],mp[i][a]+mp[a][j]);
					mp[i][j]=mp[j][i]=mn(mp[i][j],mp[i][b]+mp[b][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				sum+=mp[i][j];
			}
		}
		printf("%I64d ",sum>>1);
	}
	puts("");
	return 0;
}
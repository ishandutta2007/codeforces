#include<bits/stdc++.h>
using namespace std;
int T;
int s[200004][20];
int main(){
	for(int i=1;i<=2e5;i++)
		for(int j=0;j<20;j++){
			s[i][j]=s[i-1][j];
			if((1<<j)&i)s[i][j]++;
		}
	scanf("%d",&T);
	while(T--){
		int L,R;scanf("%d%d",&L,&R);
		int ans=2e5;
		for(int i=0;i<20;i++)ans=min(ans,R-L+1-(s[R][i]-s[L-1][i]));
		printf("%d\n",ans);
	}
}
#include<bits/stdc++.h>
#define int long long
const int N=5;
using namespace std;

int cnt[N][N],n,x,y,v[2][3],ans;

void dfs(int k,int p){
	if(k==3){
		int fl=0;
		for(int i=0;i<3;i++)	
			for(int j=i+1;j<3;j++)
				fl^=((v[0][i]!=v[0][j])||(v[1][i]!=v[1][j]));
		if(!fl)
			ans+=p;
	}
	else 
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(cnt[i][j])
					cnt[i][j]--,v[0][k]=i,v[1][k]=j,dfs(k+1,p*(cnt[i][j]+1)),cnt[i][j]++;
}

main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld%lld",&x,&y),cnt[x%4][y%4]++;
	dfs(0,1);
	printf("%lld",ans/6);
}
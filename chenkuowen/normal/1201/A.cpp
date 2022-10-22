#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+1e3;
int n,m;
int v[MAX_N][5],a[MAX_N];
char s[10005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
			v[j][s[j]-'A']++;
	}
	int ans=0;
	for(int i=1;i<=m;++i){
		int x,cnt=0; scanf("%d",&x);
		for(int j=0;j<5;++j)
			cnt=max(cnt,v[i][j]);
		ans+=cnt*x;
	}
	printf("%d\n",ans);
	return 0;
}
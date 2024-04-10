#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
int n,q;
char s[200005];
int sum[2][200005];
int main(){
	cin>>n>>q;
	scanf("%s",s+1);
	for (int i=2;i<=n;i++){
		sum[0][i]=sum[0][i-1];
		sum[1][i]=sum[1][i-1];
		if (s[i]==s[i-1])sum[s[i]-'0'][i]++;
	}
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%d\n",max(sum[0][r]-sum[0][l],sum[1][r]-sum[1][l])+1);
	}
	return 0;
}
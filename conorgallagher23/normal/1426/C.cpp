#include<bits/stdc++.h>
#define LL long long
using namespace std;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		int n,ans=1e9;
		scanf("%d",&n);
		for(int i=1;i<=100000&&i<=n;i++)ans=min(ans,i-1+((n-i)%i==0?(n-i)/i:(n-i)/i+1));
		printf("%d\n",ans);
	}
	return 0;
}
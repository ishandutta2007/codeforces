#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,cnt[4];
int main(){
	scanf("%d",&n);
	for(int t=0;t<4;t++)for(int i=0;i<n;i++)for(int j=0;j<n;j++){
		char c;cin>>c;
		if(i%2==j%2&&c=='0')cnt[t]++;
		if(i%2!=j%2&&c=='1')cnt[t]++;
	}
	sort(cnt,cnt+4);
	printf("%d\n",cnt[0]+cnt[1]+2*n*n-cnt[2]-cnt[3]);
	return 0;
}
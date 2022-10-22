#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,k,cnt[110];
signed main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d%I64d",&n,&k);
		memset(cnt,0,sizeof(cnt));
		for(int i=1,x,y;i<=n;i++){
			scanf("%I64d",&x),y=0;
			while(x)cnt[++y]+=x%k,x/=k;
		}
		bool ok=true;
		for(int i=0;i<100;i++)ok&=(cnt[i]<=1);
		puts(ok?"Yes":"No");
	}
	return 0;
}
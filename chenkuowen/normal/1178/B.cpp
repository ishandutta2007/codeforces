#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e6;
int cnt1[N],cnt2[N];
char s[N];
int main(){
	scanf("%s",s+1); int n=strlen(s+1);
	for(int i=1;i<=n;++i)
		cnt1[i]=cnt1[i-1]+(s[i]=='v'&&s[i-1]=='v');
	for(int i=n;i>=1;--i)
		cnt2[i]=cnt2[i+1]+(s[i]=='v'&&s[i+1]=='v');
	ll ans=0;
	for(int i=1;i<=n;++i)
		if(s[i]=='o')
			ans+=1ll*cnt1[i]*cnt2[i];
	printf("%lld\n",ans);
	return 0;
}
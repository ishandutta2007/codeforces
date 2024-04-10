#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000000;
int n;
char s[N+5];
int Sum[N+1],suM[N+1];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=2;i<=n;i++)Sum[i]=Sum[i-1]+(s[i-1]=='v'&&s[i]=='v');
	for(int i=n-1;i;i--)suM[i]=suM[i+1]+(s[i+1]=='v'&&s[i]=='v');
	ll ans=0;
	for(int i=1;i<=n;i++)if(s[i]=='o')ans+=1ll*Sum[i]*suM[i];
	printf("%lld",ans);
	return 0;
}
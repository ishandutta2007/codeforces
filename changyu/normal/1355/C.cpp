#include<cstdio>
#include<algorithm>
typedef long long ll;
int a,b,c,d;ll ans;
int main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	for(int s=c+1;s<=c+b;s++)ans=ans+(ll)(std::min(s-1,d)-c+1)*std::max(0,std::min(b,s-b)-std::max(a,s-c)+1);
	printf("%lld\n",ans);
	return 0;
}
#include<cstdio>
const int maxn=1100;
using namespace std;
long long n,ans,a,b;
int main(){
	scanf("%I64d",&n);
	scanf("%I64d%I64d",&a,&b);
	ans=a;
	for (long long i=1;i<n;i++){
		scanf("%I64d%I64d",&a,&b);
		ans++;
		if (ans<=a){
			ans=a;
			continue;
		}
		int x=(ans-a)%b;
		if (x==0)continue;
		ans+=b-x;
	}
	printf("%I64d\n",ans);
	return 0;
}
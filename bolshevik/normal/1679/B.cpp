#include<cstdio>
using namespace std;
const int o=2e5+10;
int n,q,a[o],tim[o],Tim=-1,Val;long long s;
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;s+=a[i++]) scanf("%d",&a[i]);
	for(int i=1,opt,pos,val;i<=q;++i,printf("%lld\n",s)){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d%d",&pos,&val);
			if(tim[pos]<Tim) s+=val-Val;
			else s+=val-a[pos];
			a[pos]=val;tim[pos]=i;
		}
		else scanf("%d",&val),s=val*1ll*n,Tim=i,Val=val;
	}
	return 0;
}
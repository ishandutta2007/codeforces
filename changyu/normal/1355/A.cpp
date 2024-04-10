#include<cstdio>
#include<algorithm>
long long a,m;
inline long long Maxdigit(long long a){
	long long s=0;
	for(;a;a/=10)s=std::max(s,a%10);
	return s;
}
inline long long Mindigit(long long a){
	long long s=9;
	for(;a;a/=10)s=std::min(s,a%10);
	return s;
}
int main(){
	int T;scanf("%d",&T);for(;T--;){
	  scanf("%lld%lld",&a,&m);
	  for(;--m;){
		if(!Mindigit(a))break;
		a+=Maxdigit(a)*Mindigit(a);
	  }printf("%lld\n",a);
	}return 0;
}
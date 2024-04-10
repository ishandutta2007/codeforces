#include<cstdio>
#include<iostream>
using namespace std;
const int o=3e5+10;
int n,a[o];long long s,ans;
inline int lowbit(int x){return x&-x;}
struct FenwickTree{
	long long b[o];
	inline void modify(int pos,int val){for(;pos<o;pos+=lowbit(pos)) b[pos]+=val;}
	inline long long query(int pos){long long res=0;for(pos=min(pos,o-1);pos;pos-=lowbit(pos)) res+=b[pos];return res;}
}t1,t2;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;printf("%lld ",ans+s*(i-1)),++i){
		scanf("%d",&a[i]);s+=a[i];ans-=t2.query(a[i]);
		for(int j=1;j*a[i]<o;++j) ans-=(t1.query((j+1)*a[i]-1)-t1.query(j*a[i]-1))*j*a[i];
		t1.modify(a[i],1);
		for(int j=1;j*a[i]<o;++j) t2.modify(j*a[i],a[i]);
	}
	return 0;
}
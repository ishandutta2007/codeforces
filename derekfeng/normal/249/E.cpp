#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 tl;
tl c1(tl l,tl r){
	return (l+r)*(r-l+1)/2;
}
tl c2(tl l,tl r){
	l--;return r*(r+1)*(r*2+1)/6-l*(l+1)*(2*l+1)/6;
}
tl calc(tl x,tl y){
	if(x<1||y<1)return 0;
	tl z=min(x,y);
	tl ans=c1(1,z*z);
	if(x==y)return ans;
	if(x<y){
		tl p=c2(x,y-1);
		p=p*x;
		tl q=c1(1,x);
		q=q*(y-x);
		return p+q+ans;
	}
	tl p=c2(y+1,x);
	p=p*y;
	tl q=c1(0,y-1);
	q=q*(x-y);
	return p-q+ans;
}
tl sol(tl a,tl b,tl c,tl d){
	return calc(c,d)+calc(a-1,b-1)-calc(a-1,d)-calc(c,b-1);
}
int main(){
	const ll MOD=1e10;
	int T;scanf("%d",&T);
	while(T--){
		int a,b,c,d;scanf("%d%d%d%d",&a,&b,&c,&d);
		tl ans=sol(a,b,c,d);
		ll res=ans%MOD;
		if(ans>=1e10)printf("..."),printf("%010lld\n",res);
		else printf("%lld\n",res);
	}
}
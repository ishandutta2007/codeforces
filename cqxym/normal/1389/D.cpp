#include<iostream>
using namespace std;
#define R register int
#define L long long
inline L Min(L x,L y){
	return x<y?x:y;
}
inline void Swap(L&x,L&y){
	int tem=x;
	x=y;
	y=tem;
}
inline void Solve(){
	L n,k,l1,r1,l2,r2;
	cin>>n>>k>>l1>>r1>>l2>>r2;
	L p=0;
	if(l1>l2){
		Swap(l1,l2);
		Swap(r1,r2);
	}
	if(r1>l2){
		p=Min(r2,r1)-l2;
		if(p*n>=k){
			puts("0");
			return;
		}
		k-=p*n;
		r1-=p;
		r2=r1+r2-l2-p;
		l2=r1;
	}
	L ans=l2-r1;
	if(r2-l1>=k){
		cout<<ans+k<<endl;
		return;
	}
	ans+=r2-l1;
	k-=r2-l1;
	for(R i=1;i!=n;i++){
		L harv=Min(k,r2-l1);
		L cost=l2-r1+harv;
		L cost2=harv<<1;
		if(cost<cost2){
			k-=harv;
			ans+=cost; 
		}else{
			break;
		}
	}
	if(k!=0){
		ans+=k<<1;
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
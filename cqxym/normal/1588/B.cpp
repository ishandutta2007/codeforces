#include<iostream>
using namespace std;
#define R register int
#define L long long
#define I inline
I L Query(int l,int r){
	cout<<"? "<<l<<' '<<r<<endl;
	L x;
	cin>>x;
	return x;
}
I int Calc(L n){
	int l=1,r=999999999,mid,res;
	n<<=1;
	while(l<=r){
		mid=l+r>>1;
		if((mid-1ll)*mid<n){
			l=mid+1;
		}else{
			res=mid;
			r=mid-1;
		}
	}
	return res;
}
I void Solve(){
	int n,l=2,r,mid,p1=1,p2,p3;
	cin>>n;
	r=n;
	L total=Query(1,n);
	while(l<=r){
		mid=l+r>>1;
		if(Query(1,mid)==0){
			p1=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	l=total-Query(p1+1,n);
	p2=p1+l;
	total-=(1ll+l)*l>>1;
	p3=p2+Calc(total);
	cout<<"! "<<p1<<' '<<p2+1<<' '<<p3<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
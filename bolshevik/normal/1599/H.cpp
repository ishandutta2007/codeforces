#include<iostream>
using namespace std;
const int E=1e9;
int d,x,y,p,q;
int main(){
	cout<<"? 1 1"<<endl;cin>>d;
	for(int l=1,r=E,md,d_;l<r;y=l){
		md=(l+r>>1)+1;
		cout<<"? 1 "<<md<<endl;cin>>d_;
		if(d-d_==md-1) l=md;
		else r=md-1;
	}
	x=d+2-y;
	cout<<"? 1 "<<E<<endl;cin>>d;
	q=E+x-d-1;
	cout<<"? "<<E<<" 1"<<endl;cin>>d;
	p=E+y-d-1;
	cout<<"! "<<x<<" "<<y<<" "<<p<<" "<<q;
	return 0;
}
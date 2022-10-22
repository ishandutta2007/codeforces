#include<iostream>
using namespace std;
const int o=1e6+10;
int l=1,r,md,a,b;
int main(){
	cin>>r;
	while(l^r){md=l+r>>1;cout<<"? "<<md<<endl;cout.flush();cin>>a;cout<<"? "<<md+1<<endl;cout.flush();cin>>b;if(a<b) r=md;else l=md+1;}
	cout<<"! "<<l;cout.flush();
	return 0;
}
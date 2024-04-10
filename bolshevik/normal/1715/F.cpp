#include<iostream>
using namespace std;
int n,m;long double x,y,s;
int main(){
	cin>>n>>m;
	cout<<"? "<<n*2+2<<"\n0 "<<m+1<<"\n";
	for(int i=0;i<n;++i) cout<<i<<" 0\n"<<i+1<<" "<<m<<"\n";
	cout<<n<<" "<<m+1<<endl;
	cin>>s;y=m*s-0.5;
	cout<<"? "<<m*2+2<<"\n"<<n+1<<" 0\n";
	for(int i=0;i<m;++i) cout<<"0 "<<i<<"\n"<<n<<" "<<i+1<<"\n";
	cout<<n+1<<" "<<m<<endl;
	cin>>s;x=n*s-0.5;
	cout<<"! "<<x<<" "<<y<<endl;
	return 0;
}
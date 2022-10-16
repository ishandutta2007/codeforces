#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a,b,x=0,y=0;
	cin>>n;
	for(int i=0;i<2*n;i++)
	{
		cin>>a>>b;
		x+=a;
		y+=b;
	}
	cout<<x/n<<' '<<y/n<<endl;
}
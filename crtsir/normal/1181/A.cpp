#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,c;
	cin>>a>>b>>c;
	cout<<(a+b)/c<<' ';
	if(a/c+b/c!=(a+b)/c)
		cout<<min((a-(a+b)%c+c)%c,(b-(a+b)%c+c)%c)<<endl;
	else
		cout<<0;
}
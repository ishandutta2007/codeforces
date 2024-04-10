#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int a,b;
		cin>>a>>b;
		b++;
		long long x=0;
		while(b)b/=10,x++;
		x--;
		cout<<a*x<<endl;
	}
}
#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,x,y;
		cin>>n>>x>>y;
		cout<<min(max(x+y+1-n,1),n)<<' ';
		if(x+y>n)
			cout<<n<<endl;
		else
			cout<<x+y-1<<endl;
	}
}
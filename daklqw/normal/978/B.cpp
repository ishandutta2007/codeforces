#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n,cnt=0,ans=0;char x;
	cin>>n;
	while(n--){
		cin>>x;
		if(x=='x')++cnt;
		else{
			if(cnt>2)ans+=cnt-2;
			cnt=0;
		}
	}
	if(cnt>2)ans+=cnt-2;
	cout<<ans<<endl;
	return 0;
}
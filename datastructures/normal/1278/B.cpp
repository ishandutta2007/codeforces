#include <iostream>
#include <cstdio>
using namespace std;
int t,a,b;
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b;
		int delta=0;
		if (a>b)delta=a-b;
		else delta=b-a;
		int ans=0,nownum=0;
		for (int i=0;;i++){
			nownum+=i;
			if (nownum>=delta&&(nownum-delta)%2==0){
				ans=i;
				break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
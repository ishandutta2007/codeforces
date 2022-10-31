#include<bits/stdc++.h>
using namespace std;
int l,r,a;
int main(){
	cin>>l>>r>>a;
	int ans = min(l,r);
	int temp = min(a,max(l,r)-min(l,r));
	ans +=temp;
	a-=temp;
	if (ans<max(l,r)){
		cout<<2*ans<<endl;
	}else{
		cout<<2*(ans+a/2)<<endl;
	}
	return 0;
}
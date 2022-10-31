#include<bits/stdc++.h>
#define int long long
const int N=100050;
using namespace std;

int gcd(int x,int y){
	return y?gcd(y,x%y):abs(x);
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n+1),ans(n+1);
	int s=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if((n&1)==0){
		ans[1]=a[2];
		ans[2]=-a[1];
	}else{
		int _1=1,_2=2,_3=3;
		if(a[1]==-a[3])
			if(a[2]!=-a[3])
				swap(_1,_2);
			else 
				swap(_2,_3);
		ans[_1]=a[_2];
		ans[_2]=-a[_1]-a[_3];
		ans[_3]=a[_2];
	}
	for(int i=(n&1)+3;i<=n;i+=2)
		ans[i]=a[i+1],ans[i+1]=-a[i];
	for(auto x:ans)
		if(x)
			cout<<x<<' ';
	cout<<endl;
}

main(){
	int t;cin>>t;
	while(t--)solve();
}
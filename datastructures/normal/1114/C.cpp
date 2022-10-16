#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,b,ans=1e18;
inline int work(int a,int b){
	int ans=0;
	while(a)ans+=a/b,a/=b;
	return ans;
}
signed main(){
	cin>>n>>b;
	for (int i=2;i*i<=b;i++){
		if (b%i!=0)continue;
		int cnt=0;
		while(b%i==0)b/=i,cnt++;
		ans=min(ans,work(n,i)/cnt); 
	}
	if (b>1)ans=min(ans,work(n,b));
	cout<<ans<<endl;
	return 0;
}
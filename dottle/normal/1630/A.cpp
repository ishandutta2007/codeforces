#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,k;cin>>n>>k;
	
		vector<int> ans(n);
		for(int i=0;i<n;i++)ans[i]=n-i-1;
	if(k==n-1)if(n<=4){cout<<-1<<endl;return;}else{
		ans[n-1]=n-2,ans[n-2]=n-1;
		ans[n/2]=0,ans[0]=n/2;
		ans[n/2-1]=1,ans[1]=n/2-1;
	}
	else if(k)
	ans[0]=n-k-1,ans[n-k-1]=0,ans[n-1]=k,ans[k]=n-1;
	for(int i=0;i<n;i++)//cout<<ans[i]<<' ';
		if(ans[i]<i)
			cout<<i<<' '<<ans[i]<<'\n';
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}
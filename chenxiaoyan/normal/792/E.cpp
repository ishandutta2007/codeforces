/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int inf=0x3f3f3f3f3f3f3f3f;
const int N=500;
int n;
int a[N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	vector<int> v;
	for(int i=1;i*i<=a[1];i++){
		v.pb(a[1]/i);
		if(a[1]%i==0&&a[1]/i>1)v.pb(a[1]/i-1);
		v.pb(i);
	}
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
	int ans=inf;
	for(int i=0;i<v.size();i++){
		bool ok=true;
		int cnt=0;
		for(int j=1;j<=n;j++){
			int least=(a[j]+v[i])/(v[i]+1);
			if(least*v[i]>a[j])ok=false;
			else cnt+=least;
		}
		if(ok)ans=min(ans,cnt);
	}
	cout<<ans;
	return 0;
}
/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int N=100000;
int n,d,m;
int a[N+1];
int Sum[N+1];
vector<int> lss,grt;
signed main(){
	cin>>n>>d>>m;
	for(int i=1;i<=n;i++){
		int x;
		scanf("%lld",&x);
		a[i]=x;
		if(x<=m)lss.pb(x);
		else grt.pb(x);
	}
	sort(lss.begin(),lss.end());sort(grt.begin(),grt.end(),greater<int>());
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)Sum[i]=Sum[i-1]+a[i];
	int now=0,ans=0,cnt=0;
	ans=Sum[lss.size()];
	for(int i=1;i<=grt.size();i++){
		if(i>1){
			cnt+=d;
			if(cnt+i>n)break;
		}
		now+=grt[i-1];
		ans=max(ans,now+Sum[lss.size()]-Sum[max(0ll,cnt-(grt.size()-i))]);
//		cout<<now<<"\n";
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e5,B=320;
int cnt[N+N],a[N];
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	memset(cnt,0,sizeof(cnt));
	int ans=0;
	for(int d=-B;d<=B;++d){
		vector<ll> f; f.reserve(n);
		for(int i=1;i<=n;++i)
			f.push_back((ll)a[i]-(ll)d*i);
		sort(f.begin(),f.end());
		int cnt=0;
		for(int i=0;i<f.size();++i){
			if(i==0||f[i]!=f[i-1]) cnt=0;
			cnt++;
			ans=max(ans,cnt);
		}
	}
	for(int i=1;i<=n;++i){
		vector<ll> f; f.reserve(B);
		for(int j=i+1;j<=min(n,i+B);++j)
			if((a[j]-a[i])%(j-i)==0)
				f.push_back((ll)(a[j]-a[i])/(j-i));
		for(auto d:f){
			cnt[d+N]++;
			ans=max(ans,cnt[d+N]+1);
		}
		for(auto d:f) cnt[d+N]--;
	}
	printf("%d\n",n-ans);
	return 0;
}
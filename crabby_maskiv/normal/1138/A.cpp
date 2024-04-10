#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
const int inf=0x3f3f3f3f;
const int mod=998244353;
int n,m;
int a[maxn];
vector<int> v;
int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i];
	int cnt=1;
	for(i=2;i<=n+1;i++){
		if(a[i]!=a[i-1]){
			v.push_back(cnt);
			cnt=0;
		}
		cnt++;
	}
	int ans=-1;
	for(i=0;i<v.size()-1;i++){
		ans=max(ans,min(v[i],v[i+1])*2);
	}
	cout<<ans;
	return 0;
}
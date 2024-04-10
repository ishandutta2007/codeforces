#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
const int M=300005;
int n,m;
vector<ll> v[4];
ll s[M];
vector<ll> tmp;
ll solve(){
	int i,j;
	ll ans=s[m/3],sum=0;
	for(i=0;i<tmp.size();i++){
		if((i+1)*2>m) return ans;
		sum+=tmp[i];
		ans=max(ans,sum+s[(m-2*(i+1))/3]);
	}
	return ans;
}
int main(){
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		ll w,c;cin>>w>>c;
		v[w].push_back(c);
	}
	for(i=1;i<=3;i++)
		sort(v[i].begin(),v[i].end(),greater<ll>() );
	for(j=0;j<v[3].size();j++) s[j+1]=s[j]+v[3][j];
	for(j=v[3].size()+1;j<=m;j++) s[j]=s[j-1];
	ll ans1=0,ans2=0;
	for(i=0;i+1<v[1].size();i+=2) tmp.push_back(v[1][i]+v[1][i+1]);
	for(i=0;i<v[2].size();i++) tmp.push_back(v[2][i]);
	sort(tmp.begin(),tmp.end(),greater<ll>());
	ans1=solve();
	if(v[1].size()){
		ans2+=v[1][0];
		m--;
		tmp.clear();
		for(i=1;i+1<v[1].size();i+=2) tmp.push_back(v[1][i]+v[1][i+1]);
		for(i=0;i<v[2].size();i++) tmp.push_back(v[2][i]);
		sort(tmp.begin(),tmp.end(),greater<ll>());
		ans2+=solve();
	}
	cout<<max(ans1,ans2);
	return 0;
}
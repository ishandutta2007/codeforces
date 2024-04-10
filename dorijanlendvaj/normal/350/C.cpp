#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
void pp(vector<vector<ll>> &v){
	for(auto v_:v)cout<<"("<<v_[0]<<","<<v_[1]<<") ";
	cout<<endl;
}
int main()
{
	ll n;cin>>n;
	vector<vector<ll>> v;
	while(n--){
		ll a,b;cin>>a>>b;
		v.emplace_back(vector<ll>{a,b});
	}
	ll x=0;
	ll y=0;
	sort(v.begin(), v.end(), [x,y](vector<ll> &a, vector<ll> &b){
		ll dist_a = (a[0]-x)*(a[0]-x) + (a[1]-y)*(a[1]-y);
		ll dist_b = (b[0]-x)*(b[0]-x) + (b[1]-y)*(b[1]-y);
		return dist_a<dist_b;});
	/*make_heap(v.begin(), v.end(), [x,y](vector<ll> &a, vector<ll> &b){
		ll dist_a = (a[0]-x)*(a[0]-x) + (a[1]-y)*(a[1]-y);
		ll dist_b = (b[0]-x)*(b[0]-x) + (b[1]-y)*(b[1]-y);
		return dist_a<dist_b;});*/
	vector<string> result;
	ll bombs=0;
	for(int i=0; i<v.size(); i++){
		auto next = v[i];
		ll horizontal = next[0] - x;
		ll vertical = next[1] - y;
		if(horizontal!=0)
			result.emplace_back("1 "+to_string(abs(horizontal))+" "+(horizontal>0?"R":"L"));
		if(vertical!=0)
			result.emplace_back("1 "+to_string(abs(vertical))+" "+(vertical>0?"U":"D"));
		result.emplace_back("2");
		if(horizontal!=0)
			result.emplace_back("1 "+to_string(abs(horizontal))+" "+(horizontal>0?"L":"R"));
		if(vertical!=0)
			result.emplace_back("1 "+to_string(abs(vertical))+" "+(vertical>0?"D":"U"));
		result.emplace_back("3");
	}
	
	cout<<result.size()<<endl;
	for(string s:result)cout<<s<<'\n';
	return 0;
}
#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;
 
const int Mod=1e9+7;

bool comp(pii p1, pii p2){
	if(p1.first!=p2.first) return p1.first<p2.first;
	return p1.second<p2.second;
}

bool comp2(pii p1, pii p2){
	if(p1.first!=p2.first) return p1.first<p2.first;
	return p1.second>p2.second;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	int n,x,y,ans;
	vector<pii> vec1,vec2;
	pii p;
	loopi(noob,t){
		cin >> n;
		int a[2*n],s[2*n+1];
		loop(2*n) cin >> a[i];
		loop(2*n) if(a[i]==2) a[i]=-1;
		s[0]=0;
		loop(2*n) s[i+1]=s[i]+a[i];
		vec1.clear();
		vec2.clear();
		loop(2*n+1){
			if(i<=n){
				p.first=s[i];
				p.second=i;
				vec1.push_back(p);
			}
			if(i>=n){
				p.first=s[i]-s[2*n];
				p.second=i;
				vec2.push_back(p);
			}
		}
		sort(vec1.begin(),vec1.end(),comp);
		sort(vec2.begin(),vec2.end(),comp2);
		ans=1e9;
		while((!vec1.empty())&&(!vec2.empty())){
			if(vec1.back().first>vec2.back().first) vec1.pop_back();
			else if(vec1.back().first<vec2.back().first) vec2.pop_back();
			else{
				ans=min(ans,vec2.back().second-vec1.back().second);
				x=vec1.back().first;
				while(vec1.back().first==x) vec1.pop_back();
				while(vec2.back().first==x) vec2.pop_back();
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
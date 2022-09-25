#include <bits/stdc++.h>

#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))

using namespace std;

const int Mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll n,a;
	cin >> n;
	ll l[n];
	vector<ll> vec[n];
	loop(n){
		cin >> l[i];
		loopi(j,l[i]){
			cin >> a;
			vec[i].push_back(a);
		}
	}
	ll ans=0;
	ll good=0;
	bool b;
	vector<ll> vec1,vec2;
	loop(n){
		b=false;
		loopi(j,l[i]-1){
			if(vec[i][j+1]>vec[i][j]){
				good++;
				b=true;
				break;
			}
		}
		if(!b){
			vec1.push_back(vec[i][0]);
			vec2.push_back(vec[i][l[i]-1]);
		}
	}
	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
	while((!vec2.empty())&&(!vec1.empty())){
		if(vec1.back()>vec2.back()){
			ans=ans+vec2.size();
			vec1.pop_back();
		}
		else{
			vec2.pop_back();
		}
	}
	ans=ans+n*n-(n-good)*(n-good);
	cout << ans << "\n";
	return 0;
}
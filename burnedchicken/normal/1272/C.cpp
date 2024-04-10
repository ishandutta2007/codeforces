#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,k;
	cin >> n >> k;
	set<char> s;
	string str;
	cin >> str;
	char c;
	loop(k){
		cin >> c;
		s.insert(c);
	}
	ll ans=0;
	ll x=0;
	loop(str.size()){
		if(s.count(str[i])) x++;
		else{
			ans+=(x+1)*x/2;
			x=0;
		}
	}
	ans+=(x+1)*x/2;
	cout << ans << endl;
	return 0;
}
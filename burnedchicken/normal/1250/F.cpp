#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) loopii(i,0,a)
#define loopii(i,b,a) for(int i=b; i<(a); i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int tt,n;
	cin >> tt;
	string s,t;
	vector<int> vec;
	set<char> s1;
	loopi(noob,tt){
		cin >> n >> s >> t;
		vec.clear();
		s1.clear();
		loop(n) if(s[i]!=t[i]) vec.push_back(i);
		if(vec.size()>2||vec.size()==1)	cout << "NO\n";
		else if(vec.size()==2){
			if(s[vec[0]]==s[vec[1]]&&t[vec[0]]==t[vec[1]]) cout << "YES\n";
			else cout << "NO\n";
		}
		else{
			loop(n) s1.insert(s[i]);
			if(s1.size()<n) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}
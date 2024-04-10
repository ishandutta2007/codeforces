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
	int q;
	cin >> q;
	loopi(noob,q){
		int n,a;
		cin >> n;
		set<int> s;
		set<int>::iterator it;
		s.clear();
		loop(n){
			cin >> a;
			if(a%2==0) s.insert(a);
		}
		int ans=0;
		while(!s.empty()){
			it=s.end();
			it--;
			a=*it;
			s.erase(it);
			a/=2;
			if(a%2==0) s.insert(a);
			ans++;
		}
		cout << ans << "\n";
	}
	return 0;
}
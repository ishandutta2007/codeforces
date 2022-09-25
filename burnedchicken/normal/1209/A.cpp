#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) loopii(i,0,a)
#define loopii(i,b,a) for(int i=b; i<(a); i++)
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pow2(x) (1ll<<(x))
 
using namespace std;

const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n,x,y,ans;
	cin >> n;
	set<int> s,s1;
	loop(n){
		cin >> x;
		s.insert(x);
	}
	ans=0;
	while(!s.empty()){
		y=*s.begin();
		s1.clear();
		forall(s,set<int>) if(*it%y) s1.insert(*it);
		s=s1;
		ans++;
	}
	cout << ans << "\n";
	return 0;
}
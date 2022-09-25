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
	int q;
	cin >> q;
	ll n,m,x,y;
	vector<int> vec;
	loopi(noob,q){
		cin >> n >> m;
		x=n/m;
		vec.clear();
		if(m%10==0) cout << "0\n";
		else if(m%5==0) cout << 5ll*((x+1)/2) << "\n";
		else if(m%2==0){
			vec.push_back(0);
			loop(x%5) vec.push_back((vec.back()+m)%10);
			y=0;
			loop(x%5+1) y+=vec[i]; 
			cout << 20ll*(x/5)+y << "\n";
		}
		else{
			vec.push_back(0);
			loop(x%10) vec.push_back((vec.back()+m)%10);
			y=0;
			loop(x%10+1) y+=vec[i];
			cout << 45ll*(x/10)+y << "\n";
		}
	}
	return 0;
}
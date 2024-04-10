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
	int t,n,cnt,ans;
	bool ok;
	cin >> t;
	loopi(noob,t){
		cin >> n;
		char a[n];
		loop(n) cin >> a[i];
		cnt=ans=0;
		ok=false;
		loop(n){
			if(a[i]=='A'){
				cnt=0;
				ok=true;
				continue;
			}
			if(!ok) continue;
			cnt++;
			ans=max(ans,cnt);
		}
		cout << ans << "\n";
	}
	return 0;
}
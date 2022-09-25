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
	int t;
	cin >> t;
	loopi(noob,t){
		int n;
		cin >> n;
		ll a[n];
		loop(n) cin >> a[i];
		ll x,y;
		x=y=0;
		loop(n) x=x+a[i];
		loop(n) y=y^a[i];
		ll ans1,ans2,ans3;
		ans1=ans2=ans3=0;
		ll d=0;
		ll target;
		while(1){
			if(d==0) target=0;
			else if((y&pow2(d-1))==0) target=0;
			else target=1;
			if((x&pow2(d))!=0&&target==0){
				ans1+=pow2(d);
				x+=pow2(d);
				y=y^pow2(d);
			}
			if((x&pow2(d))==0&&target==1){
				ans1+=pow2(d);
				x+=pow2(d);
				y=y^pow2(d);
			}
			d++;
			if(x==y*2) break;
		}
		cout << "3\n";
		cout << ans1 << ' ' << ans2 << ' ' << ans3 << "\n";
	}
	return 0;
}
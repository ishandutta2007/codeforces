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
	int n,m;
	cin >> n >> m;
	int a[n],b[n];
	loop(n) cin >> a[i];
	loop(n) cin >> b[i];
	sort(a,a+n);
	sort(b,b+n);
	bool ok;
	int x;
	vector<int> ans;
	loop(n){
		ok=true;
		x=(b[0]-a[0]+m)%m;
		loopi(j,n){
			if((b[j]-a[j]+m)%m!=x){
				ok=false;
				break;
			}
		}
		if(ok) ans.push_back(x);
		loopi(j,n-1) swap(b[j],b[j+1]);
	}
	int Min=2e9;
	loop(ans.size()) Min=min(Min,ans[i]);
	cout << Min << "\n";
	return 0;
}
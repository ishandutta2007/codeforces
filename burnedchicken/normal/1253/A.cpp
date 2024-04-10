#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

const int mod=1e9+7;
const int maxn=100005;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t,n,x;
	cin >> t;
	bool ans;
	loopi(noob,t){
		cin >> n;
		int a[n],b[n];
		loop(n) cin >> a[i];
		loop(n) cin >> b[i];
		ans=true;
		x=-1;
		loop(n){
			if(a[i]==b[i]){
				if(x!=-1) x=-2;
				continue;
			}
			if(a[i]>b[i]){
				ans=false;
				break;
			}
			if(x==-2){
				ans=false;
				break;
			}
			if(x==-1) x=b[i]-a[i];
			else if(b[i]-a[i]==x) continue;
			else{
				ans=false;
				break;
			}	
		}
		if(ans) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}
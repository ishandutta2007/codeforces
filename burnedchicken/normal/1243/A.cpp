#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=200005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	loopi(noob,t){
		int n;
		cin >> n;
		int a[n];
		loop(n) cin >> a[i];
		sort(a,a+n);
		int b[n+1];
		loop(n) b[i]=a[n-1-i];
		b[n]=-1;
		int ans;
		loop(n+1){
			if(b[i]>i) continue;
			ans=i;
			break;
		}
		cout << ans << "\n";
	}
	return 0;
}
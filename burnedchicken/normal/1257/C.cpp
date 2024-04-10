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
		int num[n+1];
		loop(n+1) num[i]=-1;
		int ans=int(1e9);
		loop(n){
			if(num[a[i]]>=0){
				ans=min(ans,i-num[a[i]]+1);
			}
			num[a[i]]=i;
		}
		if(ans==int(1e9)) cout << "-1\n";
		else cout << ans << "\n";
	}
	return 0;
}
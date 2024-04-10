#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	loopi(noob,t){
		int n;
		cin >> n;
		int a[n],pos[n];
		loop(n){
			cin >> a[i];
			a[i]--;
		}
		loop(n) pos[a[i]]=i;
		int Min=int(1e9);
		int Max=-1;
		string ans;
		ans.clear();
		loop(n){
			Min=min(Min,pos[i]);
			Max=max(Max,pos[i]);
			if(Max-Min==i) ans+='1';
			else ans+='0';
		}
		cout << ans << "\n";
	}
	return 0;
}
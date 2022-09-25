#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=200005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	loopi(noob,t){
		int a,b;
		cin >> a >> b;
		int x=abs(a-b);
		int ans=x/5;
		int y=x%5;
		if(y==1||y==2) ans++;
		if(y==3||y==4) ans+=2;
		cout << ans << "\n";
	}
	return 0;
}
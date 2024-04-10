#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int mod=1e9+7;
const int maxn=100005;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int t;
	cin >> t;
	loopi(noob,t){
		int n,x,a,b;
		cin >> n >> x >> a >> b;
		cout << min(n-1,abs(a-b)+x) << "\n";
	}
	return 0;
}
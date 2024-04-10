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
		int a,b;
		cin >> a >> b;
		if(a>=4){
			cout << "YES\n";
			continue;
		}
		if(a>=2){
			if(b<=3){
				cout << "YES\n";
				continue;
			}
		}
		if(a==1){
			if(b==1){
				cout << "YES\n";
				continue;
			}
		}
		cout << "NO\n";
	}
	return 0;
}
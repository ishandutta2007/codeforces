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
		int n;
		cin >> n;
		vector<int> ans;
		ans.clear();
		int x,ind;
		ind=1;
		while(1){
			x=n/ind;
			if(x<=ind) break;
			ans.push_back(x);
			ind++;
		}
		while(x>=0){
			ans.push_back(x);
			x--;
		}
		reverse(ans.begin(),ans.end());
		cout << ans.size() << "\n";
		loop(ans.size()) cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}
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
		int a[n];
		bool visited[n];
		loop(n){
			cin >> a[i];
			a[i]=-a[i]+i;
			visited[i]=false;
		}
		int ind,ind2;
		visited[0]=true;
		ind=0;
		while(!visited[a[ind]]){
			visited[a[ind]]=true;
			ind=a[ind];
		}
		vector<int> ans;
		ans.clear();
		ans.push_back(ind);
		ind2=a[ind];
		while(ind2!=ind){
			ans.push_back(ind2);
			ind2=a[ind2];
		}
		cout << ans.size() << "\n";
		loop(ans.size()) cout << ans[i]+1 << ' ';
		cout << "\n";
	}
	return 0;
}
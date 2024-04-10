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
		int a[n];
		loop(n) cin >> a[i];
		if(n==1){
			if(a[0]==1) cout << "1\n";
			else cout << "-1\n";
			continue;
		}
		bool boo=true;
		vector<int> ans;
		ans.clear();
		bool used[n+1];
		loop(n+1) used[i]=false;
		ans.push_back(a[0]);
		used[a[0]]=true;
		int x=1;
		loop(n-1){
			if(a[i+1]>a[i]){
				if(used[a[i+1]]){
					cout << "-1\n";
					boo=false;
					break;
				}
				ans.push_back(a[i+1]);
				used[a[i+1]]=true;
			}
			else{
				while(1){
					if(used[x]) x++;
					else break;
					if(x==n+1){
						boo=false;
						break;
					}
				}
				if(!boo){
					cout << "-1\n";
					break;
				}
				if(x>a[i+1]){
					cout << "-1\n";
					boo=false;
					break;
				}
				if(used[x]){
					cout << "-1\n";
					boo=false;
					break;
				}
				ans.push_back(x);
				used[x]=true;
			}
		}
		if(!boo) continue;
		loop(ans.size()) cout << ans[i] << " ";
		cout << "\n";
	}
	return 0;
}
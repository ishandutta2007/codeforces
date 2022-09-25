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
		int pos[n+1];
		loop(n) pos[a[i]]=i;
		bool visited[n+1];
		loop(n+1) visited[i]=false;
		int x=0;
		loop(n+1){
			if(i==0) continue;
			if(visited[i]) continue;
			if(pos[i]==x){
				visited[i]=true;
				x++;
				continue;
			}
			int y=pos[i];
			for(int j=y-1; j>=x; j--){
				swap(a[j],a[j+1]);
				swap(pos[a[j]],pos[a[j+1]]);
			}
			for(int j=x; j<y; j++){
				visited[a[j]]=true;
			}
			x=y;
		}
		loop(n) cout << a[i] << " ";
		cout << "\n";
	}
	return 0;
}
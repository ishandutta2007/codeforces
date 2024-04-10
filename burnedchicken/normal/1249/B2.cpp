#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(ll i=0; i<a; i++)
#define pll pair<ll,ll>
 
using namespace std;

const ll mod=1e9+7;

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	ll q,n,x,k,l,ans;
	cin >> q;
	loopi(j,q){
		cin >> n;
		ll a[n],num[n];
		loop(n) cin >> a[i];
		loop(n) a[i]--;
		bool visited[n];
		x=n;
		loop(n) visited[i]=false;
		vector<ll> vec;
		loop(n){
			ans=0;
			if(not visited[i]){
				k=i;
				vec.clear();
				while(1){
					ans++;
					visited[k]=true;
					vec.push_back(k);
					l=a[k];
					if(l==i){
						loopi(i1,vec.size()) num[vec[i1]]=ans;
						break;
					}
					k=l;
				}
			}
		}
		loop(n) cout << num[i] << " ";
		cout << endl;
	}
	return 0;
}
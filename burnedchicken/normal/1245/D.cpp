#include <bits/stdc++.h>
 
#define ll long long
#define loop(a) loopi(i,a)
#define loopi(i,a) for(int i=0; i<a; i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
 
using namespace std;
 
const int Mod=1e9+7;
 
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0);
	int n;
	cin >> n;
	ll x[n],y[n],c[n],k[n];
	loop(n) cin >> x[i] >> y[i];
	loop(n) cin >> c[i];
	loop(n) cin >> k[i];
	bool visited[n];
	loop(n) visited[i]=false;
	ll a[n],pre[n];
	loop(n) a[i]=c[i];
	loop(n) pre[i]=n;
	ll Min,ind,ans,dist;
	ans=0;
	loop(n){
		Min=-1;
		loopi(j,n){
			if((!visited[j])&&(Min==-1||a[j]<Min)){
				Min=a[j];
				ind=j;
			}
		}
		visited[ind]=true;
		ans+=a[ind];
		loopi(j,n){
			if(visited[j]) continue;
			dist=(k[ind]+k[j])*(abs(x[ind]-x[j])+abs(y[ind]-y[j]));
			if(dist<a[j]){
				a[j]=dist;
				pre[j]=ind;
			}
		}
	}
	cout << ans << "\n";
	vector<int> vec;
	loop(n) if(pre[i]==n) vec.push_back(i);
	cout << vec.size() << "\n";
	loop(vec.size()) cout << vec[i]+1 << " ";
	cout << "\n";
	cout << n-vec.size() << "\n";
	loop(n) if(pre[i]<n) cout << i+1 << " " << pre[i]+1 << "\n";
	return 0;
}
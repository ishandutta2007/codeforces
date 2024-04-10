#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define all(x)            (x).begin(),(x).end()
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define vc                vector
#define pii               pair<int,int>
#define msi               map<string,int>
#define mii               map<int,int>
#define psi               pair<string,int>
#define pis               pair<int,string>

vc<int> bits[25];
int found[1<<24];
void solve(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<21;i++){
		for(int j=0;j<n;j++){
			if((arr[j]>>i)&1)bits[i].pb(j);
		}
	}
	for(int i=0;i<n;i++){
		int m=i,val=0;
		while(m<n){
			val=val|arr[m];
			found[val]=1;
			m=n;
			for(int j=0;j<21;j++){
				if((val>>j)&1)continue;
				auto it=upper_bound(all(bits[j]),i);
				if(it!=bits[j].end())m=min(m,*it);
			}
		}
	}
	int c=0;
	for(int x:found)c+=x;
	cout<<c;
}
signed main(){
	ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	int t=1;
    //cin>>t;
	while(t--) solve();
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

int n;
int x[maxn],y[maxn],a[maxn],b[maxn];

map<pair<int,int> ,int> mp;
 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			mp[make_pair(x[i]+a[j],y[i]+b[j])]++; 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[make_pair(x[i]+a[j],y[i]+b[j])]>=n){
				cout<<x[i]+a[j]<<' '<<y[i]+b[j];
				return 0;
			}
		}
	}  
	return 0;
}
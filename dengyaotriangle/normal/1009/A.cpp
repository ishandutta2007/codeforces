#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

int n,m;
int x[maxn],y[maxn];
int ans;

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>x[i];
	for(int i=0;i<m;i++) cin>>y[i];
	int idxm=0;
	for(int i=0;i<n;i++){
		if(x[i]<=y[idxm]){
			ans++;
			idxm++;
		}
	}
	cout<<ans;
	return 0;
}
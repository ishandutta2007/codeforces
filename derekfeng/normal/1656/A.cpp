#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n;vector<pii>v;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			v.push_back({x,i});
		}
		sort(v.begin(),v.end());
		printf("%d %d\n",v[0].se,v.back().se);
	}
}
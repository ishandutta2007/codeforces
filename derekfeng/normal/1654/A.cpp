#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;scanf("%d",&t);
	while(t--){
		int n,x;vector<int>v;
		scanf("%d",&n);while(n--)scanf("%d",&x),v.push_back(x);
		sort(v.begin(),v.end(),greater<int>());
		printf("%d\n",v[0]+v[1]);
	}
}
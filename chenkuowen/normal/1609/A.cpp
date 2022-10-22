#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){

	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		ull mul=1;
		vector<ull> a;
		for(int i=1;i<=n;++i){
			ull x; scanf("%llu",&x);
			while(x%2==0) mul*=2,x/=2;
			a.push_back(x);
		}
		sort(a.begin(),a.end());
		a[a.size()-1]*=mul;
		ull sum=0;
		for(auto x:a) sum+=x;
		printf("%llu\n",sum);
	}
	return 0;
}
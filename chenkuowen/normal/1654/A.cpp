#include<bits/stdc++.h>
using namespace std;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		vector<int> a(n);
		for(int i=0;i<n;++i) scanf("%d",&a[i]);
		sort(a.begin(),a.end());
		printf("%d\n",a[a.size()-1]+a[a.size()-2]);
	}
	return 0;
}
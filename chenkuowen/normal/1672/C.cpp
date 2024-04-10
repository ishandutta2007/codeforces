#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
int a[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		vector<int> f;
		for(int i=1;i<n;++i)
			if(a[i]==a[i+1]) f.push_back(i);
		if(f.size()<=1) puts("0");
		else printf("%d\n",max(1,f.back()-f[0]-1));
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
int a[N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		bool flag=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]==1) flag=1;
		}
		sort(a+1,a+n+1);
		if(!flag) puts("YES");
		else {
			bool ans=1;
			for(int i=2;i<=n;++i)
				if(a[i]==a[i-1]+1) ans=0;
			if(ans) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
int a[MAX_N];
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		pair<int,int> mx(-2e9,0),mi(2e9,0);
		for(int i=1;i<=n;++i){
			if(mx.first>a[i]+i){
				puts("YES");
				printf("%d %d\n",mx.second,i);
				goto out;
			}
			if(mi.first<a[i]-i){
				puts("YES");
				printf("%d %d\n",mi.second,i);
				goto out;
			}
			mx=max(mx,make_pair(a[i]+i,i));
			mi=min(mi,make_pair(a[i]-i,i));
		}
		puts("NO");
		out:;
	}
	return 0;
}
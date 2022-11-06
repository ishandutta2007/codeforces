#include<bits/stdc++.h>
#define ll long long
#define INF 1000000002
using namespace std;
int a[200005];
set<int>S;
int main(){
	int T,n,i,j,t;
	bool flg;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",&a[i]);
		S.clear();flg=1;
		S.insert(INF);S.insert(-INF);S.insert(a[1]);
		for(i=2;i<=n;++i){
			if(a[i]<a[i-1]){
				auto it=S.lower_bound(a[i-1]);
				it--;
				if(*it>a[i]){
					flg=0;
					break;
				}
			}
			else if(a[i]>a[i-1]){
				t=*S.upper_bound(a[i-1]);
				if(t<a[i]){
					flg=0;
					break;
				}
			}
			if(!S.count(a[i]))S.insert(a[i]);
		}
		if(!flg)puts("NO");
		else puts("YES");
	}
	return 0;
}
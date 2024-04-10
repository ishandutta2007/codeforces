#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005;
int T, n, a[N], l[N], r[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) l[i]=n+1, r[i]=0;
		for(int i=1; i<=n; ++i)
			scanf("%d", a+i), l[a[i]]=min(l[a[i]], i), r[a[i]]=max(r[a[i]], i);
		int ans=0, cnt=0;
		for(int i=1; i<=n; ++i) cnt+=!!r[i];
		for(int i=1; i<=n; ++i) if(r[i]){
			int j=i, c=1, ls=r[i];
			while(j<n && l[j+1]>ls) ++j, c+=!!r[j], ls=max(ls, r[j]);
			ans=max(ans, c);
			i=j;
		}
		printf("%d\n", cnt-ans);
	}
	return 0;
}
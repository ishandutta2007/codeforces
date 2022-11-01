#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2005;
int n, ans=N, now, cnt[N], a[N];
map<int,int> f;
int main() {
	scanf("%d", &n);
	for(int i=1; i<=n; ++i)
		scanf("%d", a+i), a[i]=f[a[i]]?f[a[i]]:f[a[i]]=++now;
	for(int i=1; i<=n; ++i){
		int j=n;
		while(cnt[a[j]]<1 && j>=i) ++cnt[a[j]], --j;
		ans=min(ans, j-i+1);
		while(j<n) --cnt[a[++j]];
		if(++cnt[a[i]]>1) break;
	}
	return printf("%d\n", ans), 0;
}
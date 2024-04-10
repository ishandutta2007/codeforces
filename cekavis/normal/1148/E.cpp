#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 300005;
int n, cnt, t[N], a[N], b[N], c[N];
ll sum;
multiset<pair<int,int>> f;
int main() {
	scanf("%d", &n);
	for(int i=1, x; i<=n; ++i)
		scanf("%d", &x), sum+=x, f.insert(make_pair(x, i));
	for(int i=1; i<=n; ++i) scanf("%d", t+i), sum-=t[i];
	if(sum) return puts("NO"), 0;
	sort(t+1, t+n+1);
	for(int i=1; i<=n; ++i){
		auto l=f.lower_bound(make_pair(t[i], n+1));
		if(l==f.begin()) return puts("NO"), 0;
		auto r=l--;
		if(r==f.end()){
			if(l->first==t[i]){
				f.erase(l);
				continue;
			}
			else return puts("NO"), 0;
		}
		a[++cnt]=l->second, b[cnt]=r->second;
		c[cnt]=min(r->first-t[i], t[i]-l->first);
		if(r->first-t[i]<=t[i]-l->first)
			f.insert(make_pair(l->first+c[cnt], l->second));
		else f.insert(make_pair(r->first-c[cnt], r->second));
		f.erase(l), f.erase(r);
	}
	printf("YES\n%d\n", cnt);
	for(int i=1; i<=cnt; ++i) printf("%d %d %d\n", a[i], b[i], c[i]);
	return 0;
}
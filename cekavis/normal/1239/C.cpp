#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int n, p, now, cnt, a[N];
ll ti, ans[N];
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> q;
priority_queue<int,vector<int>, greater<int>> qq;
int main() {
	scanf("%d%d", &n, &p);
	for(int i=1; i<=n; ++i) scanf("%d", a+i), q.push(make_pair(a[i], i-n));
	now=n+1;
	while(!q.empty()){
		auto x=q.top();
		q.pop();
		ti=max(ti, x.first);
		if(x.second<=0){
			x.second=x.second+n;
			if(now>x.second)
				++cnt, now=x.second, q.push(make_pair(ti+=p, x.second));
			else qq.push(x.second);
		}
		else{
			ans[x.second]=x.first;
			--cnt;
			if(!cnt){
				if(qq.size())
					++cnt, q.push(make_pair(ti+=p, qq.top())), now=qq.top(), qq.pop();
				else now=n+1;
			}
		}
	}
	for(int i=1; i<=n; ++i) printf("%lld%c", ans[i], " \n"[i==n]);
	return 0;
}
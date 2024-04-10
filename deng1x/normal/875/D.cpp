#include <bits/stdc++.h>

#define MAXN (200010)
#define ll long long

int n;
int a[MAXN], l1[MAXN], r1[MAXN], l[MAXN], r[MAXN];
int bit[40];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; ++ i) scanf("%d", a + i);
	
	for(int i = 1; i <= n; ++ i){
		l1[i] = INT_MIN;
		
		int j = 30;
		for(; !((a[i] >> j) & 1) && a[i]; -- j);
		for(; ~j; -- j){
			if((a[i] >> j) & 1){
				bit[j] = i;
			}
			else if(bit[j]){
				l1[i] = std::max(l1[i], bit[j]);
			}
		}
	}
	
	memset(bit, 0, sizeof(bit));
	for(int i = n; i; -- i){
		r1[i] = INT_MAX;
		
		int j = 30;
		for(; !((a[i] >> j) & 1) && a[i]; -- j);
		for(; ~j; -- j){
			if((a[i] >> j) & 1){
				bit[j] = i;
			}
			else if(bit[j]){
				r1[i] = std::min(r1[i], bit[j]);
			}
		}
	}
	
	a[0] = a[n + 1] = INT_MAX;
	std::stack<int> stack;
	for(int i = 0; i <= n + 1; ++ i){
		while(!stack.empty() && a[stack.top()] <= a[i]){
			r[stack.top()] = i - 1;
			stack.pop();
		}
		if(1 <= i && i <= n) l[i] = stack.top() + 1;
		stack.push(i);
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; ++ i){
		ll L = l[i] <= l1[i] ? l1[i] - l[i] + 1 : 0;
		ll R = r[i] >= r1[i] ? r[i] - r1[i] + 1 : 0;
		ans += L * (r[i] - i + 1) + R * (i - l[i] + 1) - L * R;
	}
	
	printf("%I64d\n", ans);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int MN = 5e5 + 5;
char s[MN];
long long f (int x) {return (long long)x * (x + 1) / 2;}
long long f (int l, int r) {return f(r) - f(l-1);}
int main () {
	int n;
	scanf ("%d",&n);
	scanf ("%s",s+1);
	vector<array<long long,3>> stk; //{length, starting index, suffix sum}
	long long sum = 0, ans = 0;
	for (int i = n; i >= 1; i--) {
		if (s[i] == '1') {
			int cnt = 1;
			if (s[i+1] == '1') {
				cnt += stk.back()[0];
				stk.pop_back();
			}
			while (!stk.empty() && stk.back()[0] <= cnt)
				stk.pop_back();
			if (stk.empty()) {
				stk.push_back({cnt,i,(long long)cnt * (n - i - cnt + 2)});
				sum = f(cnt-1) + stk.back()[2];
			} else {
				auto &[len,st,old] = stk.back();
				assert(cnt < len); 
				//[i + cnt - 1, st + cnt - 1]
				long long suf = old + (long long)(st - i + 1) * cnt + f(cnt+1,len-1);
				stk.push_back({cnt,i,suf});
				sum = suf + f(cnt-1);
			}
		}
		ans += sum;
	}
	printf ("%lld\n",ans);
	return 0;
}
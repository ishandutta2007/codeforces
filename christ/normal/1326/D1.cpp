#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pli = pair<ll,int>;
using ld = long double;
#define all(x) (x).begin(),(x).end()
const int MN = 1e6+3, LOG = 18, MOD = 998244353;
char s[MN];
int main() {
	int t;
	scanf ("%d",&t);
	while (t--) {
		scanf ("%s",s);
		int n = strlen(s);
		vector<int> d1(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
			int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
			while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
				k++;
			}
			d1[i] = k--;
			if (i + k > r) {
				l = i - k;
				r = i + k;
			}
		}
		vector<int> d2(n);
		for (int i = 0, l = 0, r = -1; i < n; i++) {
			int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
			while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
				k++;
			}
			d2[i] = k--;
			if (i + k > r) {
				l = i - k - 1;
				r = i + k ;
			}
		}
		vector<int> r(n), l(n);
		int ret = 0, pre = 0, suf = 0;
		for (int i = 0; i < n; i++) {
			l[i] = min(i - d1[i] + 1, i - d2[i]);
			r[i] = max(i + d1[i] - 1, i + d2[i] - 1);
			if ((r[i] == n-1 || l[i] == 0) && r[i]-l[i]+1 > ret) {
				ret = r[i]-l[i]+1;
				pre = (l[i] == 0 ? r[i] : -1);
				suf = (l[i]==0 ? n : l[i]);
			}
		}
		int can = 0;
		for (int st = 0; st < n/2; st++) {
			if (s[st] != s[n-1-st]) break;
			++can;
		}
		vector<int> att;
		if (n&1) att.push_back(n/2);
		for (int i = n/2-1; i >= 0; i--) {
			if (i != (n-1-i)) att.push_back(n-1-i);
			att.push_back(i);
		}
		reverse(all(att));
		for (int st = can-1; st >= 0; st--) {
			if (att.empty()) break;
			while (!att.empty() && l[att.back()] > st+1 && r[att.back()] < n-st-2) att.pop_back();
			if (att.empty()) break;
			if (att.back() <= (n-1)/2 && att.back() > st && att.back() < n-st-1 && l[att.back()] <= st+1 && st*2+2+2*(att.back()-st)-1-(d1[att.back()]<att.back()-st) > ret) {
                if (att.back() + (att.back()-st) - 1-(d1[att.back()]<att.back()-st) < n-st-1) {
                    ret = st*2+2+2*(att.back()-st)-1-(d1[att.back()]<att.back()-st);
    				pre = att.back() + (att.back()-st) - 1-(d1[att.back()]<att.back()-st);
    				suf = n-st-1;
                }
			}
			if (att.back() >= n/2 && att.back() > st && att.back() < n-st-1 && r[att.back()] >= n-st-2 && st*2+2+2*(n-st-att.back()-1)-(d2[att.back()]<n-st-att.back()-1) > ret) {
                if (att.back() - (n-st-att.back()-1)+(d2[att.back()]<n-st-att.back()-1) > st) {
                    ret = st*2+2+2*(n-st-att.back()-1)-(d2[att.back()]<n-st-att.back()-1);
				    pre = st;
				    suf = att.back() - (n-st-att.back()-1)+(d2[att.back()]<n-st-att.back()-1);
                }
			}
			if (st*2+2 > ret) {
				ret = st*2+2;
				pre = st;
				suf = n-st-1;
			}
		}
		assert(ret <= n&&n-suf+pre+1==ret);
        //printf ("%d\n",ret);
		for (int i = 0; i <= min(pre,suf-1); i++) putchar(s[i]);
		for (int i = suf; i < n; i++) putchar(s[i]);
		putchar(10);
	}
    return 0;
}
#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;

const int maxn = 200005;
int stk[maxn], top, n, k;
vector<int> ans;
char s[maxn];

int main() {
	cin >> n >> k; k /= 2;
	scanf("%s", s + 1);
	rep (i, 1, n) 
		if (s[i] == '(')
			stk[++top] = i;
		else if (top) {
			if (k) {
				k--;
				ans.push_back(i);
				ans.push_back(stk[top--]);
			}
			else top--;
		}
	sort(ans.begin(), ans.end());
	for (auto p : ans)
		printf("%c", s[p]);
	return 0;
}
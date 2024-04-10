#include <bits\stdc++.h>

#define rep(i, n) for(int i = 0; i < int(n); i ++)
#define rep1(i, n) for(int i = 1; i <= int(n); i ++)

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int n;
string S, T;
vector<int> ans;

int cnt[128];

void shift(int L)
{
	ans.push_back(L);
	string tmp = S.substr(n - L);
	reverse(tmp.begin(), tmp.end());
	S = tmp + S.substr(0, n - L);
}

int main()
{
	cin >> n >> S >> T;
	rep(i, n) cnt[S[i]] ++;
	rep(i, n) cnt[T[i]] --;
	rep(i, 128) if(cnt[i]) {
		cout << "-1\n";
		return 0;
	}
	rep1(i, n)
	{
		if(S.substr(n - i) == T.substr(0, i)) continue;
		for(int j = n - i; j >= 0; j --)
		if(S[j] == T[i - 1]) {
			shift(n - j - 1);
			shift(1);
			shift(n);
			break;
		}
	}
	cout << ans.size() << '\n';
	rep(i, ans.size()) cout << ans[i] << ' ';
	return 0;
}
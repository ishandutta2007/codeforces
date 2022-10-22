#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, ans[MAXN], sz;
string s;
bool mark[MAXN];

int main(){
	getline(cin, s);	sz = s.size();
	for (int i = sz - 1, j = 1; s[i] >= '0' && s[i] <= '9' && i >= 0; i--, j *= 10)
		n = n + j * ((s[i] - '0') % 10);
	int a = 0, b = 1;
	mark[0] = 1;
	for (int i = 0; i < sz; i++)
		if (s[i] == '-')	mark[a+b] = 0, a++;
		else if (s[i] == '+')	mark[a+b] = 1, b++;
	if (b * n - a < n || b - a * n > n){
		cout << "Impossible\n";
		return 0;
	}
	int tot = a + b, sm = 0;
	for (int i = 0; i < tot; i++)
		if (!mark[i])	ans[i] = -1, sm--;
		else	ans[i] = n, sm += n;
	for (int i = 0; sm > n && i < tot; i++){
		int z = min(sm - n, n - 1);
		sm -= z;
		ans[i] -= z;
	}
	if (sm != n){
		cout << "Impossible\n";
		return 0;
	}
	cout << "Possible\n";

	cout << ans[0] << " ";
	for (int i = 1; i < tot; i++)
		if (!mark[i])
			cout << "- " << -ans[i] << " ";
		else
			cout << "+ " << ans[i] << " ";
	cout << "= ";
	cout << n << "\n";
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int MAXN = 3e5 + 10;

int n, m, b, k, ans;
string s;
int sec[MAXN], sz;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> b >> k;
	cin >> s;
	for (int i = 0; i < n;){
		if (s[i] == '1'){
			i++;
			continue;
		}
		int j = i;
		while (j < n && s[i] == s[j])	j++;
		int ln = j - i;
		if (ln >= b){
			ans += ln/b;
			for (int w = i + b-1; w < j; w += b)
				sec[sz++] = w;
		}
		i = j;
	}
	cout << ans-m+1 << "\n";
	for (int i = 0; i <ans - m + 1; i++)
		cout << sec[i]+1 << " ";
	cout << "\n";
	return 0;
}
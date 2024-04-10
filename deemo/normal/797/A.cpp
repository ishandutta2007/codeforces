#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int n, k, sec[MAXN], sz;

int main(){
	cin >> n >> k;
	for (int i = 2; i * i <= n; i++)
		while (n%i==0){
			sec[sz++] = i;
			n /= i;
		}
	if (n > 1)
		sec[sz++] = n;
	if (sz < k)
		cout << "-1\n";
	else{
		int cur = 1;
		for (int i = 0; i + k <= sz; i++)
			cur *= sec[i];
		cout << cur << " ";
		for (int i = sz-k+1; i < sz; i++)
			cout << sec[i] << " ";
		cout << "\n";
	}
	return 0;
}
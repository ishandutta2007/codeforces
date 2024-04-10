#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 20;
const int MAX = 3e6 + 10;

int n, vec[MAXN], ans, prv[MAX];
bool mark[MAX];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> vec[i], mark[vec[i]] = 1;
	sort(vec, vec + n);
	n = unique(vec, vec + n) - vec;
	for (int i = 2; i < MAX; i++)
		if (!mark[i - 1])
			prv[i] = prv[i - 1];
		else
			prv[i] = i - 1;

	for (int i = 0; i < n; i++){
		for (int j = vec[i]; ; j += vec[i]){
			int x = prv[j];
			if (x > vec[i])
				ans = max(ans, x % vec[i]);
			if (j > vec[n - 1])	break;
		}			
	}

	cout << ans << "\n";
	return	0;
}
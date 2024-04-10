#include<iostream>
#include<algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

int a, b, k, p[MAXN];
bool pr[MAXN];

int main(){
	pr[0] = pr[1] = 1;
	for (int i = 2; i < MAXN; i++)
		if (!pr[i])
			for (int j = i + i; j < MAXN; j += i)
				pr[j] = 1;
	cin >> a >> b >> k;
	for (int i = a; i <= b; i++)	p[i] = p[i - 1] + bool(!pr[i]);
	if (p[b] - p[a - 1] < k){
		cout << "-1\n";
		return	0;
	}

	int ans = 1;
	for (int i = b; i >= a; i--)
		while (p[i + ans - 1] - p[i - 1] < k){
			ans++;
			if (ans > b - i + 1)	break;
		}
	cout << ans << "\n";	
	return	0;
}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int sec[MAXN], sz;
bool pr[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	pr[0] = pr[1] = 1;
	for (int i = 2; i < MAXN; i++)
		if (!pr[i]){
			sec[sz++] = i;
			for (int j = i+i; j < MAXN; j += i)
				pr[j] = 1;
		}
	int n;	cin >> n;
	if (n+1>3)
		cout << 2 << "\n";
	else
		cout << 1 << "\n";
	for (int i = 2; i <= n+1; i++){
		if (!pr[i])
			cout << "1 ";
		else
			cout << "2 ";
	}
	cout << "\n";
	return 0;
}
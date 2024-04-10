#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k, n, s, p;
	cin >> k >> n >> s >> p;
	int req = (n+(s-1))/ s;
	req *= k;
	cout << (req+(p-1))/p << endl;
	return 0;
}
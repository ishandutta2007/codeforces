#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF int(1e9+7)

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

int a[128];

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	int cur = 1, ct = 0;
	if(a[0] == 1) {
		for(int i=1;i<n;i++) {
			if(a[i] == a[i-1]+1)
				cur++;
			else {
				break;
			}
		}
		ct = max(ct, cur-1);
	}
	if(a[n-1] == 1000) {
		cur = 1;
		for(int i=n-2;i>=0;i--) {
			if(a[i] == a[i+1]-1) {
				cur++;
			}
			else {
				break;
			}
		}
		ct = max(ct, cur-1);
	}
	cur = 1;
	for(int i=1;i<n;i++) {
		if(a[i] == a[i-1]+1) {
			cur++;
		}
		else {
			ct = max(ct, cur-2);
			cur = 1;
		}
	}
	ct = max(ct, cur-2);
	cout << ct << endl;
}
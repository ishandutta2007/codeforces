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

int a[1000005], b[1000005];
int ok1[1000005], ok2[1000005];

int main()
{
	IO_OP;
	
	int n;
	string s;
	cin >> n >> s;
	s = ' ' + s;
	
	for(int i=1;i<=n;i++) {
		if (a[i-1] <0)
			a[i] = -1;
		else if(s[i] == '(')
			a[i] = a[i-1] + 1;
		else 
			a[i] = a[i-1] - 1;
	}
	for(int i=n;i>=0;i--) {
		if (b[i+1] <0)
			b[i] = -1;
		else if(s[i] == ')')
			b[i] = b[i+1] + 1;
		else
			b[i] = b[i+1] - 1;
	}
	int ans = 0;
	for(int i=1;i<=n;i++) {
		if(s[i] == ')') {	
			if( a[i-1] >= 0 && b[i+1] >=0 &&b[i+1] - a[i-1] == 1)
				ans++;
		}
		if(s[i] == '(') {	
			if( a[i-1] >= 0 && b[i+1] >=0 &&a[i-1] - b[i+1] == 1)
				ans++;
		}
	}
	cout << ans << endl;
}
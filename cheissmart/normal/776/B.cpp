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

const int N = 100005;

bool np[N];

int main()
{
	IO_OP;
	for(int i=2;i*i<N;i++)
		if(np[i] == 0)
			for(int j = i*i;j<N;j+=i)
				np[j] = 1;
	int n;
	cin >> n;
	if(n == 1) {
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	if(n == 2) {
		cout << 1 << endl;
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	cout << 2 << endl;
	for(int i=2;i<=n+1;i++)
		cout << np[i]+1 << " ";
}
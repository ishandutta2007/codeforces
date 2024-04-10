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

int main()
{
	IO_OP;
	
	int n;
	set<int> st;
	cin >> n;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		st.insert(x);
	}
	int y = -1, z;
	for(int x:st) {
		for(int i=0;i<31;i++) {
			if(st.count(x+(1<<i))) {
				y = x, z = x+(1<<i);
				if(st.count(x+(1<<i+1))) {
					cout << 3 << endl;
					cout << x << " " << x + (1 << i) << " " << x + (1<<i+1) << endl; 
					return 0;
				}
			}
		}
	}
	if(y != -1) {
		cout << 2 << endl;
		cout << y << " " << z << endl;
	} else {
		cout << 1 << endl;
		cout << *st.begin() << endl;	
	}
}
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
	
	string s;
	vi a, b;
	cin >> s;
	for(int i=0;i<s.size();i++) {
		if(s[i] == 'l') {
			b.PB(i+1);
		} else {
			a.PB(i+1);
		}
	}
	for(int i=b.size()-1;i>=0;i--) a.PB(b[i]);
	for(int e:a) printf("%d\n", e);
	
}
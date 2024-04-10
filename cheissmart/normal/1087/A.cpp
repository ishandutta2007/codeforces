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
	cin >> s;
	int j = (s.size()+1)/2-1;
	for(int i=0;i<s.size();i++) {
		if(i % 2)
			cout << s[j+(i+1)/2];
		else 
			cout << s[j-i/2];
	}
}
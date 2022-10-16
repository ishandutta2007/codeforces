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
	int a = (s.size()+19)/20, b = (s.size()+a-1)/a, st = (b-s.size()%b)%b, spr = (st+a-1)/a;
	cout << a << " " << b << endl;
	for(int i=0, j=0;i<s.size();i++,j++) {
		if(j % b == 0) {
			if(j) cout << endl;
			for(int k=0;st && k<spr;k++,j++,st--)
				cout << '*';
		}
		cout << s[i];
	}
}
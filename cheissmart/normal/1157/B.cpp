#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back
#define ALL(v) (v).begin(), (v).end()
#define endl '\n'

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int f[11];

int main()
{
	IO_OP;
	
	int n;
	string s;
	cin >> n >> s;
	for(int i=1;i<10;i++)
		cin >> f[i];
	for(int i=0;i<n;i++) {
		if(f[s[i]-'0'] <= s[i]-'0') continue;
		while(i<n && f[s[i]-'0'] >= s[i]-'0') {
			s[i] = f[s[i]-'0'] + '0';
			i++;
		}
		break;
	}
	cout << s << endl;

}
#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define EB emplace_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int main()
{
	IO_OP;
	
	string s, t, r;
	cin >> s;
	for(int i=0,j=s.size()-1;i<=j;i+=2,j-=2) {
		if(j < i + 3) {
			r = s[i];
		} else {
			vi c(3);
			c[s[i]-'a']++, c[s[i+1]-'a']++, c[s[j]-'a']++, c[s[j-1]-'a']++;
			for(int i=0;i<3;i++)
				if(c[i] > 1) {
					t += string(1, 'a'+i);
					break;
				}
		}
	}
	cout << t << r;
	reverse(t.begin(), t.end());
	cout << t << endl;
}
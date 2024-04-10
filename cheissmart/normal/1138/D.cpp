#include <bits/stdc++.h>
#define IO_OP std::ios::sync_with_stdio(0); std::cin.tie(0);
#define F first
#define S second
#define PB push_back
#define MP make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

const int INF = 1e9 + 7;

int f[500005];

int main()
{
    IO_OP;

	string s, t, r, add;
	cin >> s >> t;
	int s0 = 0, s1 =0;
	for(char c:s) {
		if(c == '0')
			s0++;
		else
			s1++;
	}
	for(int i=1,j=f[0]=-1;i<t.size();i++) {
		while(j>=0 && t[j+1]!= t[i])
			j = f[j];
		if(t[j+1] == t[i])
			j++;
		f[i] = j;
	}
	int p = f[t.size()-1] + 1;
	add = t.substr(p);
	int c0 = 0, c1 = 0;
	for(char c:add)
        if(c == '0')
            c0++;
        else
            c1++;
	for(char c:t) {
		if(c == '0') {
			s0--;
		} else {
			s1--;
		}
	}
	if(s0 < 0 || s1 < 0) {
		cout << s << endl;
		return 0;
	}
	r += t;
	while(true) {
		if(s0 >= c0 && s1 >= c1) {
			s0 -= c0;
			s1 -= c1;
			r += add;
		} else {
			break;
		}
	}
	for(;s0;s0--)
        r += '0';
    for(;s1;s1--)
        r += '1';
	cout << r << endl;

}
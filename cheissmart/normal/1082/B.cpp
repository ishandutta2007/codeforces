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
	
	int n, cur = 0, tot = 0;
	cin >> n;
	string s;
	vi v;
	cin >> s;
	s += 'S';
	int sct = 0;
	for(int i=0;i<s.size();i++) {
		if(s[i] == 'G')
			cur++, tot++;
		else {
			if(cur) {
				if(sct > 1)
					v.PB(-1); 
				v.PB(cur);
				sct = 0;
			}
			sct++;
			cur = 0;
		}
	}
	if(v.size() == 0){
		cout << 0 << endl;
		return 0;	
	}
	if(v.size() == 1) {
		cout << v[0] << endl;
		return 0; 
	}
	int mx = -1;
	for(int e:v)
		mx = max(mx, e+1);
	for(int i=0;i<v.size()-1;i++) {
		if(v[i] == -1) continue;
		if(v[i+1] != -1) {
			mx = max(mx, v[i]+v[i+1] + 1);
			
		}
	}
	cout << min(mx, tot) << endl;
}
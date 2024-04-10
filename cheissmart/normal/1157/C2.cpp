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

int main()
{
	IO_OP;
	
	int n;
	cin >> n;
	deque<int> a(n);
	for(int i=0;i<n;i++) {
		cin >> a[i];
	}
	vi v({-1});
	string s;
	while(a.size() && (a.front() > v.back() || a.back() > v.back())) {
		if(a.front() == a.back()) {
			int i;
			for(i=1;i<a.size();i++)
				if(a[i]<=a[i-1]) break;
			int j;
			for(j=a.size()-2;j>=0;j--)
				if(a[j]<=a[j+1]) break;
			if(i > a.size()-j-1) {
				for(int k=0;k<i;k++)
					s += 'L';
			} else {
				for(int k=0;k<a.size()-j-1;k++)
					s += 'R';
			}
			break;
		}
		if(a.back() <= v.back() || (a.front() > v.back() && a.front() < a.back())) {
			v.PB(a.front());
			a.pop_front();
			s += 'L';
		} else {
			v.PB(a.back());
			a.pop_back();
			s += 'R';
		}
	}
	cout << s.size() << endl;
	cout << s << endl;
}
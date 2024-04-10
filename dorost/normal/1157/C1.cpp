#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int32_t main(){
	int n;
	cin >> n;
	deque <int> d;
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		d.push_back(x);
	}
	int x = 0;
	string s;
	while (true){
		if (d.size () == 0)
			break;
		if (min(d[0], d[d.size() - 1]) >= x){
			if (d[0] > d[d.size() - 1]){
				x = d[d.size() - 1];
				d.pop_back();
				s += 'R';
			}else{
				x = d[0];
				d.pop_front();
				s += 'L';
			}
		}else if (max(d[0], d[d.size() - 1]) >= x){
			if (d[0] > d[d.size() - 1]){
				x = d[0];
				d.pop_front();
				s += 'L';
			}else{
				x = d[d.size() - 1];
				d.pop_back();
				s += 'R';
			}
		}else{
			break;
		}
	}
	cout << s.size() << endl << s;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 200005;

vector<int> p;

int main() {
	int n,k;
	cin >> n >> k;
	int l = 0;
	for(int i = 1; i <= n; ++i) {
		p.push_back(i);
	}
	for(int i = 0; i < k; ++i) {
		int a;
		cin >> a;
		l = (l+a)%p.size();
		cout << p[l] << " ";
		p.erase(p.begin()+l);
		//if(l==p.size()) l=0;
	} cout << "\n";
	return 0;
}
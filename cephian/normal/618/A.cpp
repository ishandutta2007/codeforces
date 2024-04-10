#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

int main() {
	cin >> n;
	int p = 1;
	while(n) {
		if(n&1) v.push_back(p);
		n/=2;
		++p;
	}
	for(int i = v.size()-1; i >=0; --i)
		cout << v[i] << " ";
	cout << "\n";
}
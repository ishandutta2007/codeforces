#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ld, ld> pdd;

vector<int> a;
string out;

void buildTree(int parent, int level, bool diff, int split) {
	for(;level<a.size();++level) {
		if( diff && split == level-1 )
			cout << " " << parent+1;
		else
			cout << " " << parent;
		for(int i=1;i<a[level]; ++i) {
			cout << " " << parent;
		}
		parent += a[level-1];
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int H;
	cin >> H;
	a = vector<int>(H+1);
	int amb = -1;
	int lst = -1;
	for(int i=0;i<=H;++i) {
		cin >> a[i];
		if(a[i] > 1 && amb == -1 && i > 0 && a[i-1] > 1)
			amb = i-1;
	}
	
	if(amb == -1)
		cout << "perfect" << endl;
	else {
		cout << "ambiguous" << endl;
		cout << 0;
		buildTree(1, 1, false, amb);
		cout << "\n" << 0;
		buildTree(1, 1, true, amb);
		cout << endl;
	}
	

	
	
	
	return 0;
}
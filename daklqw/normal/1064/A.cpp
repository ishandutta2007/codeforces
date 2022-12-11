#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
namespace sdb {

	int a[3];
inline int pp(int x) { return x < 0 ? 0 : x; }
int main() {
	cin >> a[0] >> a[1] >> a[2];
	sort(a, a + 3);
	cout << pp(a[2] + 1 - (a[0] + a[1])) << endl;
	return 0;
}

}
int main() { return sdb::main(); }
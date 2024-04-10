#include <cstdio>
#include <cstdlib>

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>

#include <cctype>
#define DBG(FMT...) fprintf(stderr , FMT)

using namespace std;

int a , b;
int main() {
	cin >> a >> b;
	cout << min(a , b);
	int x = min(a , b);
	a -= x , b -= x;
	cout << " " << (a + b) / 2;
	
	return 0;
}
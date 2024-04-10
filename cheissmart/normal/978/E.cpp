#include <iostream>

using namespace std;

int main()
{
	int n, w, x, h = 0, l = 0, cur = 0;
	cin >> n >> w;
	for(int i=0;i<n;i++) {
		cin >> x;
		cur += x;
		h = max(h, cur);
		l = min(l, cur);
	}
	cout << max(w - (h - l) + 1, 0) << endl;
}
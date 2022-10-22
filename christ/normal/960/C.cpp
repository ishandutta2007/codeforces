#include <bits/stdc++.h>
using namespace std;
int main() {
	int x,d;
	scanf ("%d %d",&x,&d);
	vector<long long> arr;
	for (int i = 0; i < 30; i++) if (x >> i & 1) {
		for (int j = 0; j < i; j++) arr.push_back((long long)1e9 * 4 * i);
		arr.push_back((long long)1e9 * 4 * i + (long long)2e9);
	}
	printf ("%d\n",(int)arr.size());
	for (int i = 0; i < arr.size(); i++) printf ("%lld ",arr[i]);
	printf ("\n");
    return 0;
}
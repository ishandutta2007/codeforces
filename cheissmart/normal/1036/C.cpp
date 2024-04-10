#include <bits/stdc++.h>

using namespace std;

vector<long long> v;

void build(long long n, int len, int ct) {
	v.push_back(n);
	if(len == 18) 
		return;
	if(ct == 3) {
		build(n*10, len+1, ct);
		return;
	}
	for(int i=0;i<10;i++) {
		build(n * 10 + i,len+1,ct+(i!=0));	
	}
}

int main()
{
	int t;
	long long l, r;
	cin >> t;
	for(int i=1;i<10;i++)
		build(i, 1, 1);
	v.push_back((long long) 1e18);
	sort(v.begin(), v.end());
	while(t--) {
		cin >> l >> r;
		cout <<	upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l) << endl;
	}
}
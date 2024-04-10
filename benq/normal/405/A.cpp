#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>
 
#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
 
const int MOD = 1000000007;
const int MAX = 10000005;

int nums[100], n, max1=0;

int main() {
	cin >>n;
	F0R(i,n) {
		int x;
		cin >> x;
		if (x>max1)max1=x;
		F0R(j,x) nums[j]++;
	}
	
	F0R(i,n-1) {
		int z=0;
		F0R(j,100) {
			if (n-i <= nums[j]) {
				z++;
			}
		}
		cout << z << " ";
	}
	
	cout << max1;
	return 0;
}
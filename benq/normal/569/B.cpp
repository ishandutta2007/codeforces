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

int ans[100001], used[100001];
int j = 1;

int main() {
	int n;
	cin >> n;
	F0R(i,n) {
		cin >> ans[i];
		used[ans[i]] ++;
	}
	
	F0R(i,n) {
		while(used[j]) j++;
		if (ans[i] > n || used[ans[i]]>1) {
			used[ans[i]]--;
			ans[i] = j;
			used[j]++;
		}
		cout << ans[i] << " ";
	}
}
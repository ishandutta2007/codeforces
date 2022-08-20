#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define FORd(i, a, b) for (int i=a-1; i>=b; i--)
#define F0Rd(i, a) for (int i=a-1; i>=0; i--)
#define F0R(i, a) for (int i=0; i<a; i++)
 
#define f first
#define s second
#define be begin
#define e end
#define lb lower_bound
#define ub upper_bound
 
const int MOD = 1000000007;

int n,a,b,T, oriT,cur = 0;
int ans = 0, l = 0, u = 0;
string photos;

int test(int ind) {
	if (ind < 0) ind += n;
	if (photos[ind] == 'w') return b;
	else return 0;
}

void va() {
	while (cur<n-1 && T-a-1-test(cur+1) >= 0) {
		T = T-a-1-test(cur+1);
		cur++;
	}
	while (T-test(u-1)-2*a-1 >= 0 && u > -n) {
		T = T-test(u-1)-2*a-1;
		u--;
	}
	
	ans = cur+1-u;
	while (cur > 1) {
		T += (test(cur)+a+1);
		cur--;
		while (T-test(u-1)-2*a-1 >= 0 && u > -n) {
			T = T-test(u-1)-2*a-1;
			u --;
		}
		ans = max(cur-u+1,ans);
	//	cout << cur << " " << u << " " << T << " " << endl;
	}
}

void vb() {
	T = oriT-1-test(0), cur = n;
	u = 0;
	while (cur>1 && T-a-1-test(cur-1) >= 0) {
		T = T-a-1-test(cur-1);
		cur--;
	}
	while (T-test(u+1)-2*a-1 >= 0 && u < n) {
		T = T-test(u+1)-2*a-1;
		u++;
	}
	// cout << T << " " << u << " " << cur << endl;
	ans = max(ans,u+n-cur+1);
	while (cur < n-1) {
		T += (test(cur)+a+1);
		cur++;
		while (T-test(u+1)-2*a-1 >= 0 && u < n) {
			T = T-test(u+1)-2*a-1;
			u ++;
		}
		ans = max(n-cur+u+1,ans);
	}
}

int main() {
	cin >> n >> a >> b >> oriT >> photos;
	// n = 500000, a = 1000, b = 1000, oriT = 597933036;
	/*F0R(i,n) {
		if (rand() % 2 == 1) photos += 'h';
		else photos += 'w';
	}*/
	T = oriT-1-test(0);
	if (T == 0) {
		cout << 1;
		return 0;
	} else if (T < 0) {
		cout << 0;
		return 0;
	}
	va();
	vb();
	ans = min(ans,n);
	cout << ans;
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, a[MAXN];

int sign(int x){
	if (x > 0) return 1;
	if (x < 0) return -1;
	return 0;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	cout << "? " << 1 << endl;
	cin >> a[0];
	cout << "? " << n/2+1 << endl;
	cin >> a[n/2];
	
	int dif = a[0] - a[n/2];
	if (dif&1)
		cout << "! -1" << endl;
	else{
		if (!dif){
			cout << "! " << 1 << endl;
		}
		else{
			int lo = 0, hi = n/2;
			while (hi-lo>1){
				int mid = hi+lo>>1;
				int other = mid + n/2;
				
				cout << "? " << mid+1 << endl;
				int a; cin >> a;
				cout << "? " << other+1 << endl;
				int b; cin >> b;

				if (sign(a - b) == sign(dif))
					lo = mid;
				else
					hi = mid;
			}
			cout << "! " << hi+1 << endl;
		}
	}
	return 0;
}
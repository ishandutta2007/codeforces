#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second 

int main(){
	int n, l;
	cin >> n >> l;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a , a + n);
	int mx = 0;
	for (int i = 1; i < n; i++){
		mx = max(mx, a[i] - a[i - 1]);
	}
	if(mx / 2 >= a[0] && mx / 2 >= l - a[n - 1]){
		cout << mx / 2 << (mx % 2 ? ".5" : ".0");
	}else{
		cout << max(a[0], l - a[n - 1]);
	}
	cerr <<  endl << (float)mx / 2 << ' ' << (float)a[0] << ' ' <<  (float)l - a[n - 1];
}
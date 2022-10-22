#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(s) (int)s.size()
#define fast  ios_base::sync_with_stdio(false), cin.tie(), cout.tie()

int main(){
	int n;
	cin >> n;
	int a[2 * n];
	for (int i = 0; i < 2 * n; i++){
		cin >> a[i];
	}	
	sort(a, a + 2 * n);
	if(a[0] == a[2 * n - 1]){
		cout << -1;
	}else{
		for (int i = 0; i < 2 * n; i++){
			cout << a[i] << ' ';
		}
	}
}
#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

int main(){
	int n, m;	cin >> n >> m;
	
	int ans = 1, cnt = 0;
	while (n--){
		int x;	cin >> x;
		if (cnt + x > m){
			ans++;
			cnt = x;
		}
		else	cnt += x;
	}
	cout << ans << endl;
	return 0;
}
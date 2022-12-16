#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

inline bool containsSeven(int hh, int mm) {
	return (hh%10 == 7 || mm%10 == 7);
}

inline void minX(int& hh, int& mm, int x) {
	mm -= x;
	if(mm < 0){ 
		mm += 60;
		hh -= 1;
	}
	if(hh < 0) {
		hh += 24;
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0);
	
	int x, hh, mm;
	cin >> x >> hh >> mm;

	int cnt = 0;
	for(cnt=0;!containsSeven(hh, mm); minX(hh, mm, x), ++cnt);
	cout << cnt << endl;

	return 0;
}
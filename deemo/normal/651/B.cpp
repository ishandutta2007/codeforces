#include<iostream>

using namespace std;

const int MAXN = 1e3 + 10;

int n, cnt[MAXN], mx;

int main(){
	cin >> n;	
	int tn = n;
	while (n--){
		int temp;	cin >> temp;
		cnt[temp]++;
		mx = max(mx, cnt[temp]);
	}
	cout << tn - mx << "\n";
	return	0;
}
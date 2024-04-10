#include<iostream>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int cnt = 0;
	while (n--){
		int x;	cin >> x;
		cnt += x - 1;
		if (cnt & 1)
			cout << "1\n";
		else
			cout << "2\n";
	}
	return 0;
}
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
	string a, b;	cin >> a >> b;
	int cnt = 0, cnt2 = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i] == '1')	cnt++;
	if (cnt % 2 == 1)	cnt++;

	for (int i = 0; i < b.size(); i++)
		if (b[i] == '1')	cnt2++;
	if (cnt >= cnt2){
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
	return 0;
}
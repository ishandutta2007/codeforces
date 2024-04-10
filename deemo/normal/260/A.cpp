#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;	cin >> a >> b >> c;
	int cur = a % b;
	string s;
	while (c--){
		bool fail = 1;
		for (int i = 0; i < 10; i++)
			if ((cur * 10 + i) % b == 0){
				s += char(i + '0');
				cur = (cur * 10 + i) % b;
				fail = 0;
				break;
			}
		if (fail){
			cout << "-1\n";
			return 0;
		}
	}
	cout << a << s << "\n";
	return	0;
}
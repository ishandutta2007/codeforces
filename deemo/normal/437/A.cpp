#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int a[4];
vector<char>	vec;

int main(){
	for (int i = 0; i < 4; i++){
		char c;	cin >> c >> c;
		string s;	cin >> s;
		a[i] = (int)s.size();
	}

	if (a[0] * 2 <= min(min(a[2], a[1]), a[3]) || a[0] >= max(max(a[2], a[1]), a[3]) * 2)	vec.push_back('A');
	if (a[1] * 2 <= min(min(a[2], a[0]), a[3]) || a[1] >= max(max(a[2], a[0]), a[3]) * 2)	vec.push_back('B');
	if (a[2] * 2 <= min(min(a[0], a[1]), a[3]) || a[2] >= max(max(a[0], a[1]), a[3]) * 2)	vec.push_back('C');
	if (a[3] * 2 <= min(min(a[2], a[1]), a[0]) || a[3] >= max(max(a[2], a[1]), a[0]) * 2)	vec.push_back('D');
	if (vec.size() == 1)
		cout << vec.back() << endl;
	else
		cout << "C\n";
	return 0;
}
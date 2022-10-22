#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int rnk[200];

int main(){
	char t;	cin >> t;
	string a, b;	cin >> a >> b;
	for (int i = 6; i < 10; i++)	rnk[i + 48] = i;
	rnk['T'] = 10;
	rnk['J'] = 11;
	rnk['Q'] = 12;
	rnk['K'] = 13;
	rnk['A'] = 14;

	if (a[1] == b[1]){
		if (rnk[a[0]] > rnk[b[0]])
			cout << "YES\n";
		else
			cout << "NO\n";
		return 0;
	}
	else if (a[1] == t){
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return	0;
}
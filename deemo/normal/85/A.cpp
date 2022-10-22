#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 100 + 5;

int n;

int main(){
	cin >> n;
	if (n == 1){
		cout << "a\n";
		cout << "a\n";
		cout << "b\n";
		cout << "b\n";
		return 0;
	}
	if (n == 2){
		cout << "aa\n";
		cout << "bb\n";
		cout << "cc\n";
		cout << "dd\n";
		return 0;
	}
	if (n&1){
		for (int i = 0; i < n/2; i++)
			if (i&1)	cout << "aa";
			else	cout << "bb";
		cout << "c\n";
		for (int i = 0; i < n/2; i++)
			if (i & 1)	cout << "dd";
			else	cout << "ee";
		cout << "c\n";
		cout << "c";
		for (int i = 0; i < n/2; i++)
			if (i & 1)	cout << "zz";
			else	cout << "vv";
		cout << "\n";
		cout << "c";
		for (int i = 0; i < n/2; i++)
			if (i & 1)	cout << "qq";
			else	cout << "pp";
		cout << "\n";
	}
	else{
		for (int i = 0; i < n/2; i++)
			if (i&1)	cout << "aa";
			else	cout << "bb";
		cout << "\n";
		cout << "c";
		for (int i = 0; i < n/2 - 1; i++)
			if (i&1)	cout << "dd";
			else	cout << "ee";
		cout << "c";
		cout << "\n";
		cout << "c";
		for (int i = 0; i < n/2 - 1; i++)
			if (i & 1)	cout << "gg";
			else	cout << "hh";
		cout << "c";
		cout << "\n";
		for (int i = 0; i < n/2; i++)
			if (i & 1)
				cout << "zz";
			else
				cout << "vv";
		cout << "\n";
	}
	return	0;
}
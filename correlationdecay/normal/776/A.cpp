#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;
string s1,s2;
int main(){
	cin >> s1 >> s2;
	cout << s1 << " " << s2 << endl;
	int n;
	cin >> n;
	for(int i = 1;i <= n; i++){
		string tmp;
		cin >> tmp;
		if(tmp == s1)
			cin >> s1;
		else
			cin >> s2;
		cout << s1 << " " << s2 << endl;
	}
	return 0;
}
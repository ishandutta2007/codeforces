#include<bits/stdc++.h>
using namespace std;
int n;
string s;

int main() {
	cin >> n >> s;
	int up=0,down=0,left=0,right=0;
	for (int i=0;i<s.size();i++) {
		int c=s[i]-'0';
		if (c==1 || c==2 || c==3) up=1;
		if (c==7 || c==0 || c==9) down=1;
		if (c==1 || c==4 || c==7 || c==0) left=1;
		if (c==3 || c==6 || c==9 || c==0) right=1;
	}
	if (up && down && left && right) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}
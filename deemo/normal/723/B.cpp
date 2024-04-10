#include<bits/stdc++.h>

using namespace std;

int n;
string s;

int main(){
	cin >> n >> s;
	int a = 0 , b = 0, cc = 0, cnt = 0;
	for (int i = 0; i < n; i++){
		char ch = s[i];
		if ('A' <= ch && ch <= 'Z' || 'a' <= ch && ch <= 'z'){
			cc++;
			if (!cnt)
				a = max(a, cc);
		}
		else{
			if (ch == ')'){
				if (cc)	b++;
				cnt--;
			}
			if (ch == '('){
				cnt++;
			}
			if (ch == '_'){
				if (cnt && cc)
					b++;
			}
			cc = 0;
		}
	}
	cout << a << " " << b << endl;
	return 0;
}
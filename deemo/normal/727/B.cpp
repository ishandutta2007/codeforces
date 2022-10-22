#include<bits/stdc++.h>

using namespace std;

void f(string s, int &x, int &y){
	if (s.size() > 2 && s[(int)s.size() - 3] == '.'){
		y += int(s.back() - '0');
		s.pop_back();
		y += int(s.back() - '0') * 10;
		s.pop_back();
		s.pop_back();
	}
	int ret = 0, cur = 1;
	while (s.size()){
		if (s.back() != '.')
			ret = ret + cur * int(s.back() - '0'), cur *= 10;
		s.pop_back();
	}
	x += ret;
}

int main(){
	string t;	cin >> t;
	int x = 0, y = 0;
	for (int i = 0; i < t.size();){
		int j = i;
		while (t[j] > '9')	j++;
		string w;
		while (j < (int)t.size() && t[j] < 'A')	w += t[j++];
		f(w, x, y);
		i = j;
	}

	x += y/100;
	y %= 100;
	string s;
	if (x){
		int cnt = 0;
		while (x){
			cnt++;
			s = char(x%10+'0') + s;
			x /= 10;
			if (cnt % 3 == 0 && x)
				s = "." + s;
		}
	}
	else
		s = "0";

	cout << s;
	if (y)
		printf(".%02d", y);
	printf("\n");
	return 0;
}
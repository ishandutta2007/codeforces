#include<iostream>
#include<string>
#include<algorithm>
#include<list>

using namespace std;

const int C = 15;

int n, q, cnt[C];
string s;

void get(int l, int r){
	fill(cnt, cnt + C, 0);
	list<int>	ls(s.begin() + l, s.begin() + r);
	char dir = '>';
	list<int>::iterator it = ls.begin(), it2;
	bool fl = 0;
	while (it != ls.end()){
		char z = *it;
		if (z == '<' || z == '>'){
			if (fl)
				it2 = ls.erase(it2);
			
			fl = 1;
			it2 = it;
			dir = *it;
			if (dir == '>')	it++;
			else{
				if (it == ls.begin())	return;
				it--;
			}
		}
		else{
			cnt[z - '0']++;
			it2 = it;
			if (dir == '>')	it++;
			else{
				if (it == ls.begin())	return;
				it--;
			}
			if (it == ls.end())	return;
			if (*it2 == '0')	it2 = ls.erase(it2);
			else	(*it2)--;
			fl = 0;
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> q >> s;

	while (q--){
		int l, r;	cin >> l >> r;	l--;
		get(l, r);
		for (int i = 0; i < 10; i++)
			cout << cnt[i] << " ";
		cout << endl;
	}
	return 0;
}
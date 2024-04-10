#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>
#include<string>

using namespace std;

const int SQRT = 150;
const int max_n = 2e5 + 20;

string s;
int k, q;
vector<int>	save[200];
set<int>	st[200];

void del(int x, char c){
	set<int>::iterator it = st[c].begin();
	while (it != st[c].end()){
		if (x >= *it)
			x++;
		else	break;
		it++;
	}
	s[save[c][x]] = '1';
	st[c].insert(x);
}

void modify(){
	string temp = "";
	for (int i = 0; i < s.size(); i++)
		if (s[i] != '1')	temp += s[i];
	s = temp;
	
	for (char c = 'a'; c <= 'z'; c++){
		st[c].clear();
		save[c].clear();
	}
	
	for (int i = 0; i < s.size(); i++)
		save[s[i]].push_back(i);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> s;
	{
		string temp = s;
		s.resize(k * temp.size());
		for (int i = 0, j = 0; j < k; j++, i += temp.size())
			copy(temp.begin(), temp.end(), &s[i]);
	}
	cin >> q;
	for (int i = 0; i < q; i++){
		if (i % SQRT == 0)	modify();
		int x;
		char c;
		cin >> x >> c;	x--;
		del(x, c);
	}
	modify();
	cout << s << endl;
	return 0;
}
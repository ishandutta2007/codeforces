#include<iostream>
#include<string>
#include<algorithm>
#include<deque>
#include<utility>

using namespace std;

typedef long long ll;

bool found = 0;
int mo[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
deque<ll>	q;

ll get(string s, string t){
	int m = 0, i = 0;
	for (i = 5; i < 7; i++)
		m = (m * 10) + (s[i] - '0');
	int d = 0;
	for (i = 8; i < 10; i++)
		d = (d * 10) + (s[i] - '0');

	ll ret = 0;
	for (int i = 0; i < m - 1; i++)
		ret += mo[i] * 86400;
	ret += d * 86400;

	int h = 0;
	for (i = 0; i < 2; i++)
		h = (h * 10) + (t[i] - '0');
	int minu = 0;
	for (i = 3; i < 5; i++)
		minu = (minu * 10) + (t[i] - '0');
	int sec = 0;
	for (i = 6; i < 8; i++)
		sec = (sec * 10) + (t[i] - '0');

	ret += sec;
	ret += minu * 60;
	ret += h * 3600;
	return	ret;
}

int dif(string a, string b, string c, string d){
	return	get(c, d) - get(a, b);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;

	string s;
	getline(cin, s);
	int j = 0;
	int cnt = 0, last = 0;
	string l1, l2;
	while (getline(cin, s)){
		string tm = "" , tm2 = "";
		int i;
		for (i = 0; i < 10; i++)	tm += s[i];
		for (i = 11; i < 19; i++)	tm2 += s[i];
	
		int time = 0;
		if (j)
			time = last + dif(l1, l2, tm, tm2);
			
		while (q.size() && q.front() <= time - n)	q.pop_front();
		q.push_back(time);
		if ((int)q.size() >= m){
			found = 1;
			cout << tm << " " << tm2 << endl;
			break;
		}	

		last = time;
		l1 = tm, l2 = tm2;
		j++;
	}
	if (!found)
		cout << -1 << endl;
	return	0;
}
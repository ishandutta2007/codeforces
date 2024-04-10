//Here we go again..

#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

deque<int>	q0, q1;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s;	cin >> s;
	int n = s.size();
	vector<string>	ans;
	int c0 = 0, c1 = 0, c2 = 0;
	for (char z:s){
		if (z == '0')	c0++;
		if (z == '1')	c1++;
		if (z == '?')	c2++;
	}

	int ta = (n - 2)/2 + bool(n % 2 == 1);
	int tb = (n - 2)/2;

	if (c1 <= ta)
		ans.push_back("00");
	if (c0 <= tb)
		ans.push_back("11");

	ta++, tb++;
	if (c1 <= ta && c0 <= tb){
		string t = s;
		int g0 = c0, g1 = c1;
		for (int i = 0; i < t.size(); i++){
			if (t[i] == '?'){
				if (c0 < tb)
					t[i] = '0', c0++;
				else
					t[i] = '1', c1++;
			}	
			if (t[i] == '0')
				q0.push_back(i);
			else
				q1.push_back(i);
		}
		for (int i = 0; i < n - 2; i++){
			if (i % 2 == 0)
				q1.pop_front();
			else
				q0.pop_front();
		}
		if (q0.front() < q1.front())	
			ans.push_back("01");

		q0.clear();	q1.clear();
		c0 = g0, c1 = g1;
		t = s;
		for (int i = 0; i < t.size(); i++){
			if (t[i] == '?'){
				if (c1 < ta)
					t[i] = '1', c1++;
				else
					t[i] = '0', c0++;
			}	
			if (t[i] == '0')
				q0.push_back(i);
			else
				q1.push_back(i);
		}
		for (int i = 0; i < n - 2; i++){
			if (i % 2 == 0)
				q1.pop_front();
			else
				q0.pop_front();
		}
		if (q0.front() > q1.front())	
			ans.push_back("10");
	}
	
	sort(ans.begin(), ans.end());
	for (string v:ans)
		cout << v << endl;
	return 0;
}
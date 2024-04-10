#include <bits/stdc++.h>

using namespace std;

string name[1024];
int score[1024];
map<string, int> m, mm;

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> name[i] >> score[i];
	for(int i=0;i<n;i++)
		m[name[i]] += score[i];
	int mx = 0;
	for(auto p:m) mx = max(mx, p.second);
	for(int i=0;i<n;i++) {
		mm[name[i]] += score[i];
		if(m[name[i]] == mx && mm[name[i]] >= mx) {
			cout << name[i] << endl;
			return 0;
		}
	}

}
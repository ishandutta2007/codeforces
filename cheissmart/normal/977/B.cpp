#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	string s;
	map<string, int> m;
	cin >> n >> s;
	for(int i=0;i<n-1;i++)
		m[s.substr(i, 2)]++;
	string ans;
	int mx = 0;
	for(auto it=m.begin();it!=m.end();it++) {
		if(it->second > mx) {
			mx = it->second;
			ans = it->first;
		}
	}
	cout << ans << endl;
}
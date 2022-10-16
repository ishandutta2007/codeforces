#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	string s;
	map<char, int> a, b;
	cin >> n >> s;
	for(int i=0;i<s.size();i++)
		a[s[i]] = 1;
	int l = 0, r = 0, ans = 1e9;
	for(r = 0; r < n; r++) {
        b[s[r]]++;
        while(b.size() == a.size()) {
            b[s[l]]--;
            if(b[s[l]] == 0) b.erase(s[l]);
            ans = min(ans, r - l + 1);
            l++;
        }
    }
    cout << ans << endl;
}
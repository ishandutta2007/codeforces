#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s; cin >> s;
	string t = s;
	reverse(t.begin(), t.end());
	string temp = s;
	sort(temp.begin(), temp.end());
	if (temp[0] == temp[(int)temp.size()-1]){
		cout << "0\n";
		return 0;
	}
	if (s != t)
		cout << s.size() << "\n";
	else{
		cout << (int)s.size()-1 << "\n";
	}
	return 0;
}
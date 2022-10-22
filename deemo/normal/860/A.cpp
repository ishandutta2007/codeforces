#include<iostream>
#include<string>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

bool good[500];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	good['a'] = 1;
	good['e'] = 1;
	good['i'] = 1;
	good['o'] = 1;
	good['u'] = 1;

	string s;	cin >> s;
	for (int i = 0; i < s.size(); ){
		string t;
		int j = i;

		while (j < s.size()){
			if (!good[s[j]] && j >= i+2 && !good[s[j-1]] && !good[s[j-2]] && (s[j] != s[j-1] || s[j] != s[j-2] || s[j-1] != s[j-2])) break;
			t += s[j++];
		}

		i = j;
		cout << t << " ";
	}
	
	cout << "\n";
	return 0;
}
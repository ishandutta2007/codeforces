#include<iostream>
#include<string>

using namespace std;

const int max_n = 1e5 + 40;

string s;
int p[max_n];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++){
		if (i < s.size() - 1 && s[i] == s[i + 1])
			p[i + 1] = p[i] + 1;
		else
			p[i + 1] = p[i];
	}
	int q;	cin >> q;
	while (q--){
		int l, r;	cin >> l >> r;	
		cout << p[r - 1] - p[l - 1] << endl;
	}
	return 0;
}
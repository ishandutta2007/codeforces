#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	string s;
	cin >> s;
	bool h = false, e = false, l1 = false, l2 = false;
	for(int i = 0; i < s.size(); i++){
        if (s[i] == 'h'){
            h = true;
            continue;
        }
        if (h && s[i] == 'e'){
            e = true;
            continue;
        }
        if (h && e && s[i] == 'l' && l1 == false){
            l1 = true;
            continue;
        }
        if (h && e && l1 && s[i] == 'l'){
            l2 = true;
            continue;
        }
        if (h && e && l1 && l2 && s[i] == 'o'){
            cout << "YES";
            return 0;
        }
	}
	cout << "NO";
}
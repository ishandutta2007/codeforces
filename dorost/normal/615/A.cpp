#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n, m, x, a;
	cin >> n >> m;
	vector <int> s;
	for (int i = 0; i < n; i++){
        cin >> x;
        for (int j = 0; j < x; j++){
            cin >> a;
            s.push_back(a);
        }
	}
	for (int i = 1; i <= m; i++){
        bool f = false;
        for (int j = 0; j < s.size(); j++){
            if (i == s[j]){
                f = true;
                break;
            }
        }
        if (f == false){
            cout << "NO";
            return 0;
        }
	}
	cout << "YES";
}
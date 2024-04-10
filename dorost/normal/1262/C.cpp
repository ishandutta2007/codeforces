#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second

int main(){
	int t;
	cin >> t;
	while (t--){
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		cout << n << endl;
		int ans = 0;
		for (int i = 0; i < n; i++){
			if (i % 2 == 0){
				if (s[i] == ')'){
					bool f = false;
					for (int j = i + 1; j < n; j++){
						if (s[j] == '('){
							cout << i + 1 << ' ' << j + 1 << endl;
							f = true;
							reverse(s.begin() + i, s.begin() + j + 1);
							ans++;
							break;
						}
					}
				}
			}else{
                if (s[i] == '('){
                    bool f = false;
                    for (int j = i + 1; j < n; j++){
                        if (s[j] == ')'){ 
                            cout << i + 1 << ' ' << j + 1 << endl;
                            f = true;
							reverse(s.begin() + i, s.begin() + j + 1);
							ans++;
                            break;
                        }
                    }
                }
			}
		}
//		cout << s << endl;
		if (k == n / 2){
			for (int i = 0; i < n - ans; i++)
				cout << "1 1\n";
			continue;
		}
		k = n - k * 2;
		k += 2;
		for (int i = n - k + 1; i < n - 1; i += 2){
			cout << i + 1 << ' ' << i + 2 << endl;
//			swap(s[i], s[i + 1]);
			ans ++;
		}
		for (int i = 0; i < n - ans; i++){
			cout << "1 1\n";
		}
//		cout << s << endl;
	}
}
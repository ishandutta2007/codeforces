#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
	int n, d;
	cin >> n >> d;
	bool f[d];
	for (int i = 0; i < d; i++){
        f[i] = true;
        string s;
        cin >> s;
        for (int j = 0; j < n; j++){
            if (s[j] == '0'){
                f[i] = false;
                break;
            }
        }
	}
	vector <int> v;
	int ans = 0;
	for (int i = 0; i < d; i++){
        if (f[i]){
            v.push_back(ans);
            ans = 0;
        }else {
            ans++;
        }
	}
	v.push_back(ans);
	//if (d == 1){
      //  cout << !f[0];
        //return 0;
	//}
	sort (v.rbegin(), v.rend());
	cout << v[0];
}
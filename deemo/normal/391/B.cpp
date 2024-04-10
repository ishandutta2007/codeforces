#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int n;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;	n = s.size();
	int ans = 0;
	for (int i = 0; i < n; i++){
			int ret = 0;
			for (int j = i; j < n; j += 2){
				if (s[i] == s[j]){
					ret++;
					j--;
				}
			}
			ans = max(ans, ret);
		}
	cout << ans << endl;
	return 0;
}
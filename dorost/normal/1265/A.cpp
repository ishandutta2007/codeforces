#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int t;
	string s;
	cin >> t;
	while(t--){
		cin >> s;
		for(int i = 0; i < s.size(); i++){
			if(s[i] == '?'){
				for(int j = 0; j < 3; j++){
					if(s[i - 1] != 'a' + j && s[i + 1] != 'a' + j){
						s[i] = 'a' + j;
						break;
					}
				}
			}
		}
		bool f = true;
		for(int i = 1; i < s.size(); i++){
			if(s[i] == s[i - 1]){
				f = false;
			}
		}
		if(f){
			cout << s << endl;
		}else{
			cout << -1 << endl;
		}
	}
}
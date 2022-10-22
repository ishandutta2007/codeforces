//***in the name of GOD***//

#include<bits/stdc++.h>

using namespace std;

int main(){
	int q,n;
	string s,t;
	cin >> q;
	while(q--){
		cin >> n >> s >> t;
		bool f = true;
			int cnt = 0;
			int x,y;
			for(int j = 0; j < n; j++){
				if(cnt > 2){
					break;
				}
				if(s[j] != t[j]){
					if(cnt == 0){
						x = j;
					}else{
						y = j;
					}
					cnt++;
				}
		}
		if(cnt == 0){
			cout << "YES" << endl;
		}else if(cnt == 2){
			if(s[x] == s[y] && t[x] == t[y]){
				cout << "YES" << endl;
			}else{
				cout << "NO" << endl;
			}
		}else{
			cout << "NO" << endl;
		}
	}
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define sz(s) (int)s.size()
#define fast  ios_base::sync_with_stdio(false), cin.tie(), cout.tie()

int main(){
	 int t;
	 cin >> t;
	 while(t--){
	 	int n;
	 	cin >>  n;
	 	string s;
	 	cin >> s;
	 	bool f = true;
	 	int ans = 0;
	 	int x = 0;
	 	while(f){
	 		ans++;
	 		int p = 0;
		 	for(int i = 0; i < n - 1; i++){
		 		if(s[i] == 'A'){
		 			if(s[i + 1] == 'A'){
		 				
		 			}else{
		 				s[i + 1] = 'A';
		 				s[i] = 'A';
		 				x = ans;
		 				i++;
		 			}
		 		}
		 	}
		 	bool h = true, b = true;
		 	for(int i = 0; i < n - 1; i++){
		 		if(s[i] == 'A' && s[i + 1] == 'P'){
		 			h = false;
		 		} 
		 		if(s[i] == 'P'){
		 			b = false;
		 		}
		 	}
		 	if(h){
		 		if(!b && 0){
		 			cout << 0 << endl;
		 		}else{
		 			cout << x << endl;	
		 		}
				// << s << endl;
		 		//cerr << s << endl;
		 		break;
		 	}
		 	//ans ++;
		 }
	 }
}
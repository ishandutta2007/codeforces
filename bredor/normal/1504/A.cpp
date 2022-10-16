#include<iostream>
#include<string>
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
		string s,a="a";
		cin >> s;
		for(int i = 0; i < s.size(); i++){
			if(s[i] != 'a'){
				cout << "YES\n";
				s.insert(s.size()-i, a);
				cout << s<< endl;
				goto END;
			}
		}
		cout << "NO\n";
		END: ;
	}
}
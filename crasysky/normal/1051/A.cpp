#include <iostream>
#include <string>
using namespace std;
string s;
int a[10005];
int main(){
	int T;
	cin >> T;
	for (int i = 'a'; i <= 'z'; ++ i)
		a[i] = 0;
	for (int i = 'A'; i <= 'Z'; ++ i)
		a[i] = 1;
	for (int i = '0'; i <= '9'; ++ i)
		a[i] = 2;
	while (T --){
		cin >> s;
		int n = s.length();
		int flag[3];
		flag[0] = flag[1] = flag[2] = 0;
		for (int i = 0; i < n; ++ i)
			flag[a[s[i]]] ++;
		if (flag[0] && flag[1] && flag[2]){
			cout << s << endl;
			continue;
		}
		if ((flag[0] == 0) + (flag[1] == 0) + (flag[2] == 0) == 1){
			for (int i = 0; i < n; ++ i)
				if (flag[a[s[i]]] > 1){
					if (flag[0] == 0)
						s[i] = 'a';
					if (flag[1] == 0)
						s[i] = 'A';
					if (flag[2] == 0)
						s[i] = '1';
					cout << s << endl;
					break;
				}
		}
		else{
			for (int cas = 0; cas <= 1; ++ cas){
				if (flag[0] == 0)
					s[cas] = 'a', flag[0] = 1;
				else if (flag[1] == 0)
					s[cas] = 'A', flag[1] = 1;
				else if (flag[2] == 0)
					s[cas] = '1', flag[2] = 1;
			}
			cout << s <<endl;
		}
	}
}
#include<iostream>
#include<string>

using namespace std;

bool mark[200];

int main(){
	int n, t;	cin >> n >> t;
	string s;	cin >>s ;
	while (t--){
		for (int i = 0; i < 200; i++)	mark[i] = 0;
		for (int i = 0; i < n - 1; i++)
			if (!mark[i] && s[i] == 'B' && s[i + 1] == 'G'){
				mark[i] = mark[i + 1] = 1;
				swap(s[i], s[i + 1]);
			}
	}	
	cout << s << endl;
	return 0;
}
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

string str, a;
int n;

int main(){
	cin >> n >> a >> str;
	if(str == "month"){
		if(n <= 29)cout << 12 << endl;
		else if(n <= 30)cout << 11 << endl;
		else cout << 7 << endl;
	}
	if(str == "week"){
		if(n == 5 || n == 6)cout << 53 << endl;
		else cout << 52 << endl;	
	}
	return 0;
}
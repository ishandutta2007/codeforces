#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str, ans;
int num;
int res = -2000000000;
int m = 2000000000;
int main(){
int n;
	cin >> n;
	for(int i = 0;i < n;i++){
		cin >> str >> num >> ans;
		if(str == ">=" && ans == "Y" || str == "<" && ans == "N"){
			res = max(res, num);
		}
		if(str == ">=" && ans == "N" || str == "<" && ans == "Y"){
			m = min(m, num - 1);
		}
		if(str == ">" && ans == "Y" || str == "<=" && ans == "N"){
			res = max(res, num + 1);
		}
		if(str == ">" && ans == "N" || str == "<=" && ans == "Y"){
			m = min(m, num);
		}
	}
	if(res <= m)
		cout << res << endl;
	else
		cout << "Impossible" << endl;
	return 0;
}
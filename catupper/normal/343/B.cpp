#include <iostream>
#include<string>
using namespace std;
string x;
int main() {
	cin >> x;
	int res = 0;
	for(int i = 0;i < x.size();i++){
		if(i&1){
			if(x[i] == '+')res++;
			else res--;
		}
		else{
			if(x[i] == '+')res--;
			else res++;
		}
	}
	if(res)cout << "No"<<endl;
	else cout << "Yes"<<endl;return 0;
}
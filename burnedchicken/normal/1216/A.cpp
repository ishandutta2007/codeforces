#include <iostream>
#include <string>

using namespace std;

int main(){
	string str;
	cin >> str >> str;
	int x=0;
	for(int i=0; i<str.size()/2; i++){
		if(str[2*i]==str[2*i+1]){
			x++;
			if(str[2*i]=='a') str[2*i]='b';
			else str[2*i]='a';
		}
	}
	cout << x << endl << str << endl;
	return 0;
}
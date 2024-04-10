#include <iostream>
#include <string>

using namespace std;
int main(){
	string n;
	cin >> n;
	char min='z';
	for(int i=0; i<n.size(); i++){
		if(n[i]<min) min=n[i];
		if(min<n[i]) cout << "Ann" << endl;
		else cout << "Mike" << endl;
	}
	return 0;
}
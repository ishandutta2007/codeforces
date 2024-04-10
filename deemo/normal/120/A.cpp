#include<fstream>
#include<string>

using namespace std;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	string s;	cin >> s;
	int t;	cin >> t;
	if ((t == 1 && s == "front") || (t == 2 && s == "back"))
		cout << "L\n";
	else
		cout << "R\n";
	return 0;
}
//obvious!

#include<iostream>
#include<string>

using namespace std;

string s[40] = {"Washington", "Adams", "Jefferson", "Madison", "Monroe", "Adams", "Jackson", "Van Buren", "Harrison", "Tyler", "Polk", "Taylor", "Fillmore", "Pierce", "Buchanan", "Lincoln", 
	"Johnson", "Grant", "Hayes", "Garfield", "Arthur", "Cleveland", "Harrison", "Cleveland", "McKinley", "Roosevelt", "Taft", "Wilson", "Harding", "Coolidge", "Hoover", "Roosevelt", "Truman",
	"Eisenhower", "Kennedy", "Johnson", "Nixon", "Ford", "Carter", "Reagan"};

int main(){
	int x;	cin >> x;	x--;
	cout << s[x] << endl;
	return 0;
}
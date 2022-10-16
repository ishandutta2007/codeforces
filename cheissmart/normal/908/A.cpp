#include <iostream>

using namespace std;

int main()
{
	string s;
	int ct = 0;
	cin >> s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='1' || s[i]=='3' || s[i]=='5' ||s[i]=='7' || s[i]=='9' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u')
			ct++;
	cout << ct << endl;
}
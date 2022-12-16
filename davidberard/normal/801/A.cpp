#include <bits/stdc++.h>

using namespace std;
typedef long long int lli;
typedef pair<int, int> pii;

int countIt(string s)
{
	int pos = 0;
	int counter = 0;
	while((pos=s.find("VK", pos)) != string::npos){
		++pos;
		++counter;
	}
	return counter;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;
	int max = countIt(s);
	char old;
	for(int i=0;i<s.length();++i)
	{
		old = s.at(i);
		s.at(i) = 'V';
		if(countIt(s) > max)
			max = countIt(s);
		s.at(i) = 'K';
		if(countIt(s) > max)
			max = countIt(s);
		s.at(i) = old;
	}
	cout << max << endl;


	return 0;
}
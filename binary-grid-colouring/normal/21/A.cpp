#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	string s;
	cin>>s; 
	regex re1("[A-Za-z0-9_]{1,16}@[A-Za-z0-9_.]{1,32}(/[A-Za-z0-9_]{1,16})?");
	regex r3("[A-Za-z0-9_]{1,16}@[A-Za-z0-9_]{1,16}(.[A-Za-z0-9_]{1,16})*(/[A-Za-z0-9_]{1,16})?");

	if (regex_match(s, r3) && regex_match(s,re1))
	{
		cout << "YES" <<endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
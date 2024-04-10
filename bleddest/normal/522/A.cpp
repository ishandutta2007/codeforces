#include<vector>
#include<iostream>
#include<set>
#include<random>
#include<ctime>
#include<cstdio>
#include<map>
#include<string>

using namespace std;

void to_lower_case(string& s)
{
 	for(int i = 0; i < s.size(); i++)
 		if(s[i] >= 'A' && s[i] <= 'Z')
 			s[i] = char(s[i] + 'a' - 'A');
}

int main()
{                                        
	map<string, int> m;	
	m["polycarp"] = 1;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
	 	string x, y;
	 	cin >> x;
	 	cin >> y; //   reposted
	 	cin >> y;
	 	to_lower_case(x);
	 	to_lower_case(y);
	 	m[x] = m[y] + 1; 
	}

	int ans = 0;
	for(auto x : m)
		ans = max(ans, x.second);
   	cout << ans << endl;
}
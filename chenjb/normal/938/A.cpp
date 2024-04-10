#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <bitset>
using namespace std;
string s;
int n;
bool vowel(char c)
{
	if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='y')return 1;
	return 0;
}
int main()
{
	cin>>n;
	char c;
	getchar();
	s="";
	for(int i=1;i<=n;i++){ scanf("%c",&c); s+=c; }
	while (1)
	{
		string ts="";
		int flag=0;
		for(int j=0;j<s.length();j++)
		{
			if (j!=0 && vowel(s[j-1]) && vowel(s[j]) && !flag){ flag=1; continue; }
			ts+=s[j];
		}
		s=ts;
		if (!flag)break;
	}
	cout<<s<<endl;
}
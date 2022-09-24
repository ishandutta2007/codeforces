#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int A[150];
string s;
int i,ans;

int main()
{
	cin.sync_with_stdio(false);

	cin>>s;

	for(i=0;i<s.size();i++) A[s[i]]++;

	ans = s.size();
	ans = min(ans,A['B']);
	ans = min(ans,A['u']/2);
	ans = min(ans,A['l']);
	ans = min(ans,A['b']);
	ans = min(ans,A['a']/2);
	ans = min(ans,A['s']);
	ans = min(ans,A['r']);

	printf("%d",ans);

	return 0;
}
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;
char s[100009];
map<char,int>mp;
int main(){
	scanf("%s",s);
	int n = strlen(s);
	for(int i = 0; i < n; i++){
		mp[s[i]]++;
	}
	int ans = mp['B'];
	ans = min (ans, mp['u']/2);
	ans = min (ans, mp['l']);
	ans = min (ans, mp['b']);
	ans = min (ans, mp['a']/2);
	ans = min(ans, mp['s']);
	ans =min(ans, mp['u']);
	ans =min(ans,mp['r']);
	cout<<ans<<endl;
	return 0;

}
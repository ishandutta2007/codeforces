#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string s,t[5];
int fg=0;
int main(){
	cin>>s;
	for (int i=0;i<5;i++){
		cin>>t[i];
		if (t[i][0]==s[0]||t[i][1]==s[1])fg=1;
	}
	if (fg==1)puts("YES");
	else puts("NO");
	return 0;
}
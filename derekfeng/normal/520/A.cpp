#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;string s;cin>>n>>s;
	int msk=0;
	for(int i=0;i<n;i++){
		if('A'<=s[i]&&s[i]<='Z')msk|=(1<<(s[i]-'A'));
		else msk|=(1<<(s[i]-'a'));
	}
	if(msk==(1<<26)-1)puts("YES");
	else puts("NO");
}
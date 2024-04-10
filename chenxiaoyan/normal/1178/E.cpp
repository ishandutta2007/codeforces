#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
int n;
char s[N+5];
string ans;
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<n/2;i+=2)
		if(s[i]==s[n+1-i]||s[i]==s[n-i])ans+=s[i];
		else ans+=s[i+1];
	if(n/2&1)cout<<ans<<s[n+1>>1],cout<<(reverse(ans.begin(),ans.end()),ans);
	else cout<<ans,cout<<(reverse(ans.begin(),ans.end()),ans);
	return 0;
}
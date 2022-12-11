#include<bits/stdc++.h>
using namespace std;
char s[111111],t[111111];
int dp[2];
int main(){
	int tt;cin>>tt;while(tt--){
		scanf("%s%s",s+1,t+1);
		int ls=strlen(s+1),lt=strlen(t+1),pt=1;
		for(int i=1+(ls-lt)%2;i<=ls;i+=2)if(s[i]==t[pt]){
			pt++;i--;
			if(pt>lt){puts("Yes");goto Y;}
		}puts("No");Y:;
	}
}
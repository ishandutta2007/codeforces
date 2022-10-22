#include<bits/stdc++.h>
using namespace std;
int t,n;
char s[100004];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s+1);
		int i=2;
		for(;i<=n&&(s[i]<s[i-1]||(i>2&&s[i]==s[i-1]));i++);
		for(int j=1;j<i;j++)putchar(s[j]);
		for(int j=i-1;j;j--)putchar(s[j]);
		puts("");
	}
}
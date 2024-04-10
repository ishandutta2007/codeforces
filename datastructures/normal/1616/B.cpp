#include <iostream>
#include <cstdio>
using namespace std;
int t,n;
char s[100005];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		scanf("%s",s+1);
		int p=1;
		if (s[1]==s[2])p=1;
		else{
			while(p<n&&s[p]>=s[p+1])p++;
		}
		for (int i=1;i<=p;i++)putchar(s[i]);
		for (int i=p;i>=1;i--)putchar(s[i]);
		puts("");
	}
	return 0;
}
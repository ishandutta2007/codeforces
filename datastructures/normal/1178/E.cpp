#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
char s[1000005];
int l,r;
int book[1000005];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	l=1,r=n;
	while(r-l>2){
		if (s[l]==s[r]||s[l]==s[r-1])while(s[l]!=s[r])r--;
		else{
			l++;
			while(s[l]!=s[r])r--;
		}
		book[l]=1,book[r]=1;
		l++,r--;
	}
	book[l]=1;
	for (int i=1;i<=n;i++)
		if (book[i]==1)putchar(s[i]);
	puts("");
	return 0;
}
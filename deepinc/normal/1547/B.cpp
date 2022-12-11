#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[222];
int main(){
	int t;cin>>t;while(t--){
		cin>>s;
		int n=strlen(s),r,l,c='b';
		for(l=r=0;s[l]&&s[l]!='a';++l,++r);
		if(l==n){puts("NO");goto E;}
		while(l||r!=n-1){
			if(l&&s[l-1]==c)l--;
			else if(r!=n-1&&s[r+1]==c)r++;
			else {puts("NO");goto E;}
			c++;
		}puts("YES");E:;
	}
}
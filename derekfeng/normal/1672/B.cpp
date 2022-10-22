#include<bits/stdc++.h>
using namespace std;
int t;
char s[200004];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		int n=strlen(s);
		int cur=0;
		bool ok=s[n-1]=='B';
		for(int i=0;i<n;i++){
			cur+=s[i]=='A'?1:-1;
			if(cur<0)ok=0;
		}
		puts(ok?"YES":"NO");
	}
}
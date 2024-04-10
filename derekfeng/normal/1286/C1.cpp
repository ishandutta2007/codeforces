#include <bits/stdc++.h>
using namespace std;
void read(short &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
void write(short x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
void writes(string s){
	for (int i=0;i<s.size();i++) putchar(s[i]);
}
short n;
short cnt[103][26];
string s,ans;
int main(){
	read(n);
	if (n==1){
		puts("? 1 1");
		fflush(stdout);
		reads(s);
		writes("! "),writes(s);return 0;
	}
	writes("? 1 ");write(n);puts("");fflush(stdout);
	for (short i=1;i<=n*(n+1)/2;i++){
		reads(s);
		for (short j=0;j<s.size();j++) cnt[s.size()][s[j]-'a']++;
	}
	writes("? 2 ");write(n);puts("");fflush(stdout);
	for (short i=1;i<=n*(n-1)/2;i++){
		reads(s);
		for (short j=0;j<s.size();j++) cnt[s.size()][s[j]-'a']--;
	}
	for (short i=1;i<=n;i++){
		short ok;
		for (short j=0;j<26;j++) if (cnt[i][j]){
			ans+=j+'a',ok=j;
			break;
		}
		for (short j=1;j<=n;j++) cnt[j][ok]--;
	}
	writes("! "),writes(ans);
}
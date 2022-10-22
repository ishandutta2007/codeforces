#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
	char ch=getchar();s="";
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
int q,num[200004][26];
string s; 
int main(){
	reads(s),read(q);
	int n=s.size();
	s="$"+s;
	for (int i=1;i<=n;i++){
		for (int j=0;j<26;j++) num[i][j]=num[i-1][j];
		num[i][s[i]-'a']++;
	}
	while (q--){
		int l,r;
		read(l),read(r);
		if (l==r){
			puts("Yes");
			continue;
		}
		if (s[l]!=s[r]){
			puts("Yes");
			continue;
		}
		int lt=0;
		for (int i=0;i<26;i++) if (num[r][i]-num[l-1][i]>0 && i!=s[l]-'a') lt++;
		if (lt>1){
			puts("Yes");
			continue;
		}
		puts("No");
	}
}
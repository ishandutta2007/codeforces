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
void write(string s){
	for (int i=0;i<s.size();i++) putchar(s[i]);
}
int Tc,mch[2000004];
string s,S,suf;
void Manacher(){
	s="$|";
	for (int i=0;i<S.size();i++) s+=S[i],s+="|";
	s+="@";
	int Maxlen=0,wic,mid=0,r=0;
	for (int i=1;i+1<s.size();i++){
		if (i<=r) mch[i]=min(r-i+1,mch[2*mid-i]);
		else mch[i]=0;
		while (s[i+mch[i]]==s[i-mch[i]]) mch[i]++;
		if (i+mch[i]>r) r=i+mch[i]-1,mid=i;
		if ((i-mch[i]==0 || i+mch[i]==s.size()-1)&&mch[i]>Maxlen) Maxlen=mch[i],wic=i; 
	}
	for (int i=wic-Maxlen+1;i<=wic+Maxlen-1;i++) if ('a'<=s[i] && s[i]<='z') putchar(s[i]);
}
int main(){
	read(Tc);
	while (Tc--){
		reads(s);
		int l=0,r=s.size()-1;
		while (r>l && s[l]==s[r]) l++,r--;
		suf="";
		if (l!=0) suf=s.substr(0,l);
		write(suf);
		if (l<=r){
			S=s.substr(l,r-l+1);
			Manacher();
		}
		reverse(suf.begin(),suf.end());
		write(suf),puts("");
	}
}
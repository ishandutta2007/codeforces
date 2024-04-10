#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void getstring(string &s){
	char ch=getchar();s="";
	for (;ch!='\n';s+=ch,ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int k,m,n;string s;
int slen[1000004],bf[1000004];
int nxt(int x,int t){
	int l=x-1,r=n+1;
	while (r>l+1){
		int mid=(l+r)/2;
		if (bf[mid]-bf[x-1]<=t) l=mid;
		else r=mid;
	}
	return l;
}
short check(int x){
	int num=0;
	for (int i=1;;){
		if (num==k) return 0;
		int go=nxt(i,x);
		if (go==n) break;
		i=go+1;
		num++;
	}
	return 1;
}
int main(){
	read(k);getstring(s);
	m=s.size();
	int num=0;
	for (int i=0;i<m;i++){
		if (s[i]=='-' || s[i]==' '){
			slen[++n]=++num;
			num=0;
		}
		else num++;
	}
	slen[++n]=num;
	for (int i=1;i<=n;i++) bf[i]=bf[i-1]+slen[i];
	int l=-1,r=1e6+2;
	while (r>l+1){
		int mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid;
	}
	write(r);
}
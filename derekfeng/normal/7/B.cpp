#include <bits/stdc++.h>
using namespace std;
void read(short &x){
	char ch=getchar();x=0;
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void reads(string &s){
	char ch=getchar();s="";
	for(;ch==' '||ch=='\n';ch=getchar());
	for(;ch!=' '&&ch!='\n';s+=ch,ch=getchar());
}
write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
short a[103],cnt=0;
short oprs,n;
void ALLOC(){
	short x;read(x);
	short sml=-1;
	for (short i=1;i<=n-x+1;i++){
		short yes=1;
		for (short j=i,k=0;k<x && yes;j++,k++) if (a[j]) yes=0;
		if (yes){
			sml=i;break;
		}
	}
	if (sml==-1){
		puts("NULL");
		return;
	}
	++cnt;
	for (short i=sml,j=0;j<x;i++,j++) a[i]=cnt;
	write(cnt);puts("");
}
void ERASE(){
	short x;read(x);
	if (x<=0){
		puts("ILLEGAL_ERASE_ARGUMENT");return;
	}
	short yes=0;
	for (short i=1;i<=n;i++)
		if (a[i]==x) a[i]=0,yes=1;
	if (!yes) puts("ILLEGAL_ERASE_ARGUMENT");
}
void DEFRAGMENT(){
	int now=0;
	for (int i=1;i<=n;i++){
		if (a[i]!=0) a[++now]=a[i];
		if (i!=now) a[i]=0;
	}
}
string oper;
int main(){
	read(oprs),read(n);
	while (oprs--){
		reads(oper);
		if (oper[0]=='a'){
			ALLOC();
		}
		if (oper[0]=='e'){
			ERASE();
		}
		if (oper[0]=='d'){
			DEFRAGMENT();
		}
	}
}
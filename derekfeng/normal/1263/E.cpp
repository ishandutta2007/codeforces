#include <bits/stdc++.h>
using namespace std;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
    if (x<0){
        putchar('-');
        write(-x);
        return;
    }
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
char oper;
int n,n_=1;
int dats[2100000],datb[2100000],cnt[2100000];
int mouse_=0,num=0,lstans=0;
char s[1000001];
void recovery(int l,int r,int id,int a,int b,int add){
	if (r<a || b<l) return;
	if (a<=l && r<=b){
		dats[id]+=add,datb[id]+=add;
		cnt[id]+=add;
		return;
	}
	recovery(l,(l+r)/2,id*2+1,a,b,add);
	recovery((l+r)/2+1,r,id*2+2,a,b,add);
	dats[id]=min(dats[id*2+1]+cnt[id],dats[id*2+2]+cnt[id]);
	datb[id]=max(datb[id*2+1]+cnt[id],datb[id*2+2]+cnt[id]);
}
int main(){
	read(n);
	while(n_<n) n_<<=1;
	for (int i=1;i<=n;i++){
		oper=getchar();
		if (oper=='L'){
		   write(lstans),putchar(' ');
			mouse_--;
			mouse_=max(mouse_,0);
			continue;
		}
		if (oper=='R'){
		   write(lstans),putchar(' ');
			mouse_++;
			continue;
		}
		int lst,nw;
		if (s[mouse_]=='(') lst=1;
		else if (s[mouse_]==')') lst=-1;
		else lst=0;
		if (oper=='(') nw=1;
		else if (oper==')') nw=-1;
		else nw=0;
		nw-=lst;
		s[mouse_]=oper;
		recovery(0,n_-1,0,mouse_,n_-1,nw);
		num+=nw;
		if (num!=0 || dats[0]<0){
		    lstans=-1;
		    write(-1),putchar(' '); 
		}else lstans=datb[0],write(datb[0]),putchar(' ');
	}
}
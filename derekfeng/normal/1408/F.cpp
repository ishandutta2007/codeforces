#include<bits/stdc++.h>
using namespace std;
const int SIZ=6;
char buf1[SIZ],*p1=buf1,*p2=buf1;
char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
int read(){int ret;register int c;while((c=gchar())>'9'||c<'0');ret=c-'0';while((c=gchar())>='0'&&c<='9')ret=ret*10+c-'0';return ret;}
void write(int x){if(x>9)write(x/10);putchar(x%10+'0');}
int n_=1,n,cnt;
int X[106497],Y[106497];
inline void solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid),solve(mid+1,r);
	for(int i=l,j=mid+1;i<=mid;i++,j++)cnt++,X[cnt]=i,Y[cnt]=j;
}
int main(){
	n=read();
	while((n_<<1)<n)n_<<=1;
	solve(1,n_),solve(n-n_+1,n);
	write(cnt),puts("");
	for(int i=1;i<=cnt;i++)write(X[i]),putchar(' '),write(Y[i]),puts("");
}
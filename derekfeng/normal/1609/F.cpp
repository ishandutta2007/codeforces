#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
typedef long long ll;
namespace IO{
	const int SIZ=(1<<25);
	char buf1[SIZ],*p1=buf1,*p2=buf1;
	char buf2[SIZ],*p3=buf2,*p4=buf2;
	char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
	void pchar(char c){*p4++=c;if(p4-p3==SIZ)fwrite(buf2,1,SIZ,stdout),p4=buf2;}
	void output(){fwrite(buf2,1,p4-p3,stdout);}
}
using namespace IO;
typedef long long ll;
ll read(){ll ret=0;int c;while((c=gchar())>'9'||c<'0');ret=c-'0';while((c=gchar())>='0'&&c<='9')ret=ret*10+c-'0';return ret;}
void write(ll x){if(x>9)write(x/10);pchar(x%10+'0');}
struct node{
	int L,R,sum;
	bool v;
	ll val;
	node(){
		L=R=0,val=sum=0,v=0;
	}
}sta1[1000005],sta2[1000005];
int N1,N2;
void push1(int l,int r,ll v,int p){
	++N1,sta1[N1]=sta1[N1-1];
	sta1[N1].L=l,sta1[N1].R=r;
	sta1[N1].val=v,sta1[N1].v=p;
	if(p)sta1[N1].sum+=r-l+1;
}
void push2(int l,int r,ll v,int p){
	++N2,sta2[N2]=sta2[N2-1];
	sta2[N2].L=l,sta2[N2].R=r;
	sta2[N2].val=v,sta2[N2].v=p;
	if(p)sta2[N2].sum+=r-l+1;
}
int n;
ll a[1000005],ans;
int S;
int bs1(int pos){
	if(N1==0||pos==0)return 0;
	if(pos>sta1[N1].R)return sta1[N1].sum;
	int l=0,r=N1+1;
	while(r>l+1){
		int md=(l+r)>>1;
		if(pos<=sta1[md].R)r=md;
		else l=md;
	}
	int tmp=sta1[r-1].sum;
	if(sta1[r].v)tmp+=pos-sta1[r].L+1;
	return tmp;
}
int bs2(int pos){
	if(N2==0||pos==0)return 0;
	if(pos>sta2[N2].R)return sta2[N2].sum;
	int l=0,r=N2+1;
	while(r>l+1){
		int md=(l+r)>>1;
		if(pos<=sta2[md].R)r=md;
		else l=md;
	}
	int tmp=sta2[r-1].sum;
	if(sta2[r].v)tmp+=pos-sta2[r].L+1;
	return tmp;
}
int calc1(int L,int R){
	return bs2(R)-bs2(L-1);
}
int calc2(int L,int R){
	return bs1(R)-bs1(L-1);
}
void sol(int p){
	N1=N2=0;S=0;
	ll x;
	for(int i=1;i<=n;i++){
		x=a[i];int v=(__builtin_popcountll(x)==p);
		while(N1>0&&sta1[N1].val<=x){
			if(sta1[N1].v)S-=calc1(sta1[N1].L,sta1[N1].R);
			N1--;
		}
		while(N2>0&&sta2[N2].val>=x){
			if(sta2[N2].v)S-=calc2(sta2[N2].L,sta2[N2].R);
			N2--;
		}
		if(v)S+=calc1(sta1[N1].R+1,i);push1(sta1[N1].R+1,i,x,v);
		if(v)S+=calc2(sta2[N2].R+1,i);push2(sta2[N2].R+1,i,x,v);
		ans+=S;
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<=60;i++)sol(i);
	write(ans),output();
}
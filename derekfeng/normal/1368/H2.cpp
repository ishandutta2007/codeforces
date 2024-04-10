#include<bits/stdc++.h>
using namespace std;
namespace IO{
	const int SIZ=(1<<25);
	char buf1[SIZ],*p1=buf1,*p2=buf1;
	char buf2[SIZ],*p3=buf2,*p4=buf2;
	char gchar(){if(p1==p2)p1=buf1,p2=buf1+fread(buf1,1,SIZ,stdin);return p1==p2?EOF:*p1++;}
	void pchar(char c){*p4++=c;if(p4-p3==SIZ)fwrite(buf2,1,SIZ,stdout),p4=buf2;}
	void output(){fwrite(buf2,1,p4-p3,stdout);}
};
using namespace IO;
void read(int &x){x=0;int c;while((c=gchar())>'9'||c<'0');x=c-'0';while((c=gchar())>='0'&&c<='9')x=x*10+c-'0';}
void reads(char *s){int c;while((c=gchar())>'Z'||c<'A');*s++=c;while((c=gchar())>='A'&&c<='Z')*s++=c;}
void write(int x){if(x>9)write(x/10);pchar(x%10+'0');}
const int inf=1e7;
struct mat{
	int a00,a01,a10,a11;
	mat(int a00=0,int a01=0,int a10=0,int a11=0):
		a00(a00),a01(a01),a10(a10),a11(a11){}
	mat operator *(const mat &o){
		return mat(
			min(a00+o.a00,a01+o.a10),
			min(a00+o.a01,a01+o.a11),
			min(a10+o.a00,a11+o.a10),
			min(a10+o.a01,a11+o.a11)
		);
	}
};
int n,m,q;
char h[2][500005],w[2][500005];
struct SegTree{
	struct node{
		mat f00,f01,f10,f11;
		int l,r,d1,d2;
		bool lz1,lz2;
	}d[1100000];
	void push1(int i){
		swap(d[i].f00,d[i].f10),swap(d[i].f01,d[i].f11);
		d[i].lz1^=1,d[i].d1=d[i].r-d[i].l+1-d[i].d1;
	}
	void push2(int i){
		swap(d[i].f00,d[i].f01),swap(d[i].f10,d[i].f11);
		d[i].lz2^=1,d[i].d2=d[i].r-d[i].l+1-d[i].d2;
	}
	void pushdown(int i){
		if(d[i].lz1)push1(i<<1),push1(i<<1|1),d[i].lz1=0;
		if(d[i].lz2)push2(i<<1),push2(i<<1|1),d[i].lz2=0;
	}
	void pushup(int i){
		int ls=i<<1,rs=i<<1|1;
		d[i].f00=d[ls].f00*d[rs].f00;
		d[i].f01=d[ls].f01*d[rs].f01;
		d[i].f10=d[ls].f10*d[rs].f10;
		d[i].f11=d[ls].f11*d[rs].f11;
		d[i].d1=d[ls].d1+d[rs].d1;
		d[i].d2=d[ls].d2+d[rs].d2;
	}
	void upd1(int i,int a,int b){
		if(d[i].r<a||b<d[i].l)return;
		if(a<=d[i].l&&d[i].r<=b)return push1(i);
		pushdown(i);
		upd1(i<<1,a,b),upd1(i<<1|1,a,b);
		pushup(i);
	}
	void upd2(int i,int a,int b){
		if(d[i].r<a||b<d[i].l)return;
		if(a<=d[i].l&&d[i].r<=b)return push2(i);
		pushdown(i);
		upd2(i<<1,a,b),upd2(i<<1|1,a,b);
		pushup(i);
	}
	void built(int i,int L,int R,char *a,char *b,int t){
		d[i].l=L,d[i].r=R;
		d[i].lz1=d[i].lz2=0;
		d[i].d1=d[i].d2=0;
		if(L==R){
			int t1=a[L]=='B',q1=t1^1;
			int t2=b[L]=='B',q2=t2^1;
			d[i].d1=t1,d[i].d2=t2;
			if(L==1){
				d[i].f00=mat(t1+t2,inf,inf,q1+q2);
				d[i].f01=mat(t1+q2,inf,inf,q1+t2);
				d[i].f10=mat(q1+t2,inf,inf,t1+q2);
				d[i].f11=mat(q1+q2,inf,inf,t1+t2);
			}else{
				d[i].f00=mat(t1+t2,q1+q2+t,t1+t2+t,q1+q2);
				d[i].f01=mat(t1+q2,q1+t2+t,t1+q2+t,q1+t2);
				d[i].f10=mat(q1+t2,t1+q2+t,q1+t2+t,t1+q2);
				d[i].f11=mat(q1+q2,t1+t2+t,q1+q2+t,t1+t2);
			}
		}else{
			int M=(L+R)>>1;
			built(i<<1,L,M,a,b,t);
			built(i<<1|1,M+1,R,a,b,t);
			pushup(i);
		}
	}
}R,C;
int qryr(){
	int ans=inf;
	int t1=C.d[1].d1,t2=C.d[1].d2;
	int q1=m-t1,q2=m-t2;
	mat ret=R.d[1].f00;
	ans=min(ans,ret.a00+t1+t2);
	ans=min(ans,ret.a01+t1+q2);
	ans=min(ans,ret.a10+q1+t2);
	ans=min(ans,ret.a11+q1+q2);
	return ans;
}
int qryc(){
	int ans=inf;
	int t1=R.d[1].d1,t2=R.d[1].d2;
	int q1=n-t1,q2=n-t2;
	mat ret=C.d[1].f00;
	ans=min(ans,ret.a00+t1+t2);
	ans=min(ans,ret.a01+t1+q2);
	ans=min(ans,ret.a10+q1+t2);
	ans=min(ans,ret.a11+q1+q2);
	return ans;
}
int main(){
//	freopen("line.in","r",stdin);
//	freopen("line.out","w",stdout);
	read(n),read(m),read(q);
	for(int i=0;i<2;i++)reads(h[i]+1);
	for(int i=0;i<2;i++)reads(w[i]+1);
	R.built(1,1,n,h[0],h[1],m);
	C.built(1,1,m,w[0],w[1],n);
	write(min(qryr(),qryc())),pchar('\n');
	while(q--){
		char op[6];int l,r;
		reads(op),read(l),read(r);
		if(*op=='L')R.upd1(1,l,r);
		if(*op=='R')R.upd2(1,l,r);
		if(*op=='U')C.upd1(1,l,r);
		if(*op=='D')C.upd2(1,l,r);
		write(min(qryr(),qryc())),pchar('\n');
	}
	output();
}
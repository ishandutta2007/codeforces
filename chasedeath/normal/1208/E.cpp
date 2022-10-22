#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=1e6+10;

int n,m;
ll ds[N],s[N];
int cnt,a[N];
struct Node{
	int l,r,x;
	bool operator < (const Node __) const{
		return x>__.x;
	}
}A[N];
int fa[N];
int Find(int x){ 
	int t=x;
	while(fa[x]!=x) x=fa[x];
	while(fa[t]!=t) {
		int nxt=fa[t];
		fa[t]=x;
		t=nxt;
	}
	return x;
}



void Work1() {
	rep(i,1,m) fa[i]=i;
	rep(i,1,cnt) A[i]=(Node){i,m-(cnt-i),a[i]};
	if(cnt<m) {
		int t=cnt;
		A[++cnt]=(Node){t+1,m,0};
		A[++cnt]=(Node){1,m-t,0};
	}
	sort(A+1,A+cnt+1);
	fa[m+1]=m+1;
	rep(i,1,cnt) {
		int p=Find(A[i].l);
		//cout<<"A"<<A[i].l<<' '<<A[i].r<<' '<<A[i].x<<endl;
		while(p<=A[i].r) {
			//cout<<"Add p="<<p<<' '<<A[i].x<<endl;
			s[p]+=A[i].x;
			fa[p]=p+1;
			p=Find(p);
		}
	}
}




void Work2(){
	int ma=0;
	rep(i,1,cnt) ma=max(ma,a[i]);
	ds[cnt]+=ma,ds[m-cnt+2]-=ma;
	rep(i,1,cnt) fa[i]=i;
	drep(i,m,m-cnt+1) fa[i]=i;
	fa[m+1]=m+1;
	fa[cnt]=m-cnt+2;
	rep(i,1,cnt) A[i]=(Node){i,m-(cnt-i),a[i]};
	A[++cnt]=(Node){1,m,0};
	sort(A+1,A+cnt+1);
	rep(i,1,cnt) {
		int p=Find(A[i].l);
		while(p<=A[i].r) {
			s[p]+=A[i].x;
			fa[p]=p+1;
			p=Find(p);
		}
	}
}


int main(){
	n=rd(),m=rd();
	rep(ttt,1,n) {
		cnt=rd();
		rep(i,1,cnt) a[i]=rd();
		if(cnt>m/2) Work1();
		else Work2();
	}
	rep(i,1,m) {
		ds[i]+=ds[i-1];
		printf("%lld ",s[i]+ds[i]);
	}
}
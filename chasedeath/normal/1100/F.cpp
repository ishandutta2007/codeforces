#include<bits/stdc++.h>
using namespace std;



typedef long long ll;
#define reg register
#define rep(i,a,b) for(reg int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(reg int i=a,i##end=b;i>=i##end;--i)


char IO;
inline int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}


const int N=5e5+10;

int n,m;
int a[N];
int d[30],t[30];

struct Query{
	int l,r,id;
	void Get(int i){ l=rd(),r=rd(),id=i; }
	bool operator < (const Query __) const{
		return r<__.r;
	}
}Q[N];

inline void Insert(int x,int id){
	drep(i,20,0) if(x&(1<<i)) {
		if(d[i]) x^=d[i];
		else {
			d[i]=x;
			t[i]=id;
			break;
		}
	}
}

int tmp[N];
inline void Ins(int x,int id){
	int mi=1e9,p=-1;
	drep(i,20,0) if(x&(1<<i)) {
		if(d[i]) {
			x^=d[i];
			if(t[i]<mi) mi=t[i],p=i;
		} else {
			d[i]=x,t[i]=id;
			break;
		}
	}
	int cnt=0;
	//cout<<"Insert "<<mi<<' '<<p<<endl;
	if(!x&&~p) t[p]=id;
	drep(j,20,0) if(d[j]) tmp[++cnt]=t[j],d[j]=0;
	sort(tmp+1,tmp+cnt+1,greater<int>());
	rep(j,1,cnt) Insert(a[tmp[j]],tmp[j]);
}

int Que(int p){
	int res=0;
	//rep(i,0,20) if(d[i]) cout<<"$"<<i<<' '<<t[i]<<' '<<' '<<d[i]<<endl;
	drep(i,20,0) if(t[i]>=p) {
		if((res^d[i])>res) res^=d[i];
		//cout<<"Can go"<<i<<' '<<t[i]<<' '<<p<<endl;
	}
	return res;
}


int ans[N];
int main(){
	rep(i,1,n=rd()) a[i]=rd();
	rep(i,1,m=rd()) Q[i].Get(i);
	sort(Q+1,Q+m+1);
	int p=1;
	rep(i,1,n) {
		//cout<<"Insert i="<<i<<endl;
		Ins(a[i],i);
		while(p<=m && Q[p].r<=i) {
			//puts("");
			//cout<<"Begin Query"<<Q[p].l<<' '<<Q[p].r<<endl;
			ans[Q[p].id]=Que(Q[p].l);
			p++;
		}
	}
	rep(i,1,m) printf("%d\n",ans[i]);
}
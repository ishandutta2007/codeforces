#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 10,inf=0x3f3f3f3f;
int n,ans;bool heng[N];
struct dot{
	int x,y;
	dot(int X=0,int Y=0){x=X;y=Y;}
}s[N],dest[N],yzr[N];int id[N];
dot operator +(dot a, dot b){return dot(a.x+b.x,a.y+b.y);}
dot operator -(dot a, dot b){return dot(a.x-b.x,a.y-b.y);}
bool operator ==(dot a, dot b){return a.x==b.x&&a.y==b.y;}
int Abs(int x){return x>0?x:-x;}
int achievable(dot a){return !a.x||!a.y?Abs(a.x)+Abs(a.y):-1;}
void test(){
//	if(yzr[1]==s[1]&&yzr[2]==s[2]&&yzr[3]==s[3]&&yzr[4]==s[4])puts("OwO");
	bool ok=1;rep(i,1,4)ok&=achievable(yzr[i]-s[i])>=0;
	ok&=yzr[id[1]].y==yzr[id[2]].y&&yzr[id[2]].x>yzr[id[1]].x;
	ok&=yzr[id[2]].x==yzr[id[3]].x&&yzr[id[3]].y>yzr[id[2]].y;
	ok&=yzr[id[3]].y==yzr[id[4]].y&&yzr[id[3]].x>yzr[id[4]].x;
	ok&=yzr[id[4]].x==yzr[id[1]].x&&yzr[id[4]].y>yzr[id[1]].y;
	int tmp=yzr[id[2]].x-yzr[id[1]].x;
	if(ok&&tmp==yzr[id[3]].y-yzr[id[2]].y&&tmp==yzr[id[3]].x-yzr[id[4]].x&&tmp==yzr[id[4]].y-yzr[id[1]].y){
		tmp=0;rep(i,1,4)umax(tmp,achievable(yzr[i]-s[i]));
		if(tmp<ans){
			ans=tmp;
			rep(i,1,4)dest[i]=yzr[i];
		}
	}
}
void solve(){
	if(heng[id[2]]&&!heng[id[4]]){
		yzr[id[1]]=dot(s[id[4]].x,s[id[2]].y);
		if(heng[id[3]]){
			if(s[id[3]].y<=s[id[2]].y)return;int l=s[id[3]].y-s[id[2]].y;
			yzr[id[2]]=yzr[id[1]]+dot(l,0);
			yzr[id[3]]=yzr[id[1]]+dot(l,l);
			yzr[id[4]]=yzr[id[1]]+dot(0,l);
			test();
		}
		else{
			if(s[id[3]].x<=s[id[4]].x)return;int l=s[id[3]].x-s[id[4]].x;
			yzr[id[2]]=yzr[id[1]]+dot(l,0);
			yzr[id[3]]=yzr[id[1]]+dot(l,l);
			yzr[id[4]]=yzr[id[1]]+dot(0,l);
			test();
		}
		return;
	}
	if(heng[id[4]]&&!heng[id[2]]){
		yzr[id[3]]=dot(s[id[2]].x,s[id[4]].y);
		if(heng[id[1]]){
			int l=s[id[4]].y-s[id[1]].y;
			yzr[id[2]]=yzr[id[3]]-dot(0,l);
			yzr[id[4]]=yzr[id[3]]-dot(l,0);
			yzr[id[1]]=yzr[id[3]]-dot(l,l);
			test();
		}
		else{
			int l=s[id[2]].x-s[id[1]].x;
			yzr[id[2]]=yzr[id[3]]-dot(0,l);
			yzr[id[4]]=yzr[id[3]]-dot(l,0);
			yzr[id[1]]=yzr[id[3]]-dot(l,l);
			test();
		}
		return;
	}
	if(heng[id[4]]&&heng[id[2]]){
		if(!heng[id[1]]){
			yzr[id[1]]=dot(s[id[1]].x,s[id[2]].y);int l=s[id[4]].y-s[id[2]].y;
			yzr[id[2]]=yzr[id[1]]+dot(l,0);
			yzr[id[3]]=yzr[id[1]]+dot(l,l);
			yzr[id[4]]=yzr[id[1]]+dot(0,l);
			test();return;
		}
		if(!heng[id[3]]){
			yzr[id[3]]=dot(s[id[3]].x,s[id[4]].y);int l=s[id[4]].y-s[id[2]].y;
			yzr[id[2]]=yzr[id[3]]-dot(0,l);
			yzr[id[4]]=yzr[id[3]]-dot(l,0);
			yzr[id[1]]=yzr[id[3]]-dot(l,l);
			test();return;
		}
		static int v[5]={0};int l=s[id[4]].y-s[id[2]].y;
		v[1]=s[id[1]].x;
		v[2]=s[id[2]].x-l;
		v[3]=s[id[3]].x-l;
		v[4]=s[id[4]].x;
		sort(v+1,v+5);int delta=(v[1]+v[4])/2;
	//	cerr<<"qwq "<<delta<<endl;
		rep(i,1,4)yzr[i]=s[i];yzr[id[1]].x=yzr[id[4]].x=delta;yzr[id[2]].x=yzr[id[3]].x=delta+l;
		test();
		return;
	}
	if(!heng[id[4]]&&!heng[id[2]]){
		int l=s[id[2]].x-s[id[4]].x;
		if(heng[id[1]]){
			yzr[id[1]]=dot(s[id[4]].x,s[id[1]].y);
			yzr[id[2]]=yzr[id[1]]+dot(l,0);
			yzr[id[3]]=yzr[id[1]]+dot(l,l);
			yzr[id[4]]=yzr[id[1]]+dot(0,l);
			test();return;
		}
		if(heng[id[3]]){
			yzr[id[3]]=dot(s[id[2]].x,s[id[3]].y);
			yzr[id[2]]=yzr[id[3]]-dot(0,l);
			yzr[id[4]]=yzr[id[3]]-dot(l,0);
			yzr[id[1]]=yzr[id[3]]-dot(l,l);
			test();return;
		}
		static int v[5]={0};
		v[1]=s[id[1]].y;
		v[2]=s[id[2]].y;
		v[3]=s[id[3]].y-l;
		v[4]=s[id[4]].y-l;
		sort(v+1,v+5);int delta=(v[1]+v[4])/2;
		rep(i,1,4)yzr[i]=s[i];yzr[id[1]].y=yzr[id[2]].y=delta;yzr[id[3]].y=yzr[id[4]].y=delta+l;
		test();
		return;
	}
}
int main() {
	int T;read(T);while(T--){
		rep(i,1,4)read(s[i].x),read(s[i].y);ans=inf;
		for(id[1]=1;id[1]<=4;id[1]++)
		for(id[2]=1;id[2]<=4;id[2]++)
		for(id[3]=1;id[3]<=4;id[3]++)
		for(id[4]=1;id[4]<=4;id[4]++)
		if(id[1]!=id[2]&&id[1]!=id[3]&&id[1]!=id[4]&&id[2]!=id[3]&&id[2]!=id[4]&&id[3]!=id[4])
		rep(S,0,15){rep(i,1,4)heng[i]=S>>i-1&1;solve();}
		if(ans==inf)puts("-1");
		else{
			printf("%d\n",ans);
			rep(i,1,4)printf("%d %d\n",dest[i].x,dest[i].y);
		}
	}
	return 0;
}
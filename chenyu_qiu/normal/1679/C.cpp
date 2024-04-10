#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
#define maxn 100010
struct seg{
	int t[maxn<<2];
	void init(){memset(t,0,sizeof(t));}
	void update(int o,int l,int r,int x,int v){
		if(l==r){
			t[o]+=v;
			return;
		}
		int mid=(l+r)>>1;
		if(x<=mid)update(o<<1,l,mid,x,v);
		else update(o<<1|1,mid+1,r,x,v);
		t[o]=min(t[o<<1],t[o<<1|1]);
	}
	int queue(int o,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr)return t[o];
		int mid=(l+r)>>1,ans=maxn*10;
		if(ql<=mid)ans=min(ans,queue(o<<1,l,mid,ql,qr));
		if(qr>mid)ans=min(ans,queue(o<<1|1,mid+1,r,ql,qr));
		return ans;
	}
}tx,ty;
int main(){
	tx.init(),ty.init();
	int n=getint(),q=getint();
	while(q--){
		int t=getint(),x1=getint(),y1=getint(),x2,y2;
		if(t==1){
			tx.update(1,1,n,x1,1);
			ty.update(1,1,n,y1,1);
		}
		else if(t==2){
			tx.update(1,1,n,x1,-1);
			ty.update(1,1,n,y1,-1);
		}
		else{
			x2=getint(),y2=getint();
			int t1=tx.queue(1,1,n,x1,x2),t2=ty.queue(1,1,n,y1,y2);
			if(max(t1,t2)==0)puts("No");
			else puts("Yes");
		}
	} 
	return 0;
}
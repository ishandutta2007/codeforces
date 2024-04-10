#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 
char s[1000005],a[1000005];
int n,tot,now;
struct SGT{
	int mn[8000005],mx[8000005],tag[8000005];
	inline void mem(){
		for (int i=0;i<=4*n+1;i++)
			mn[i]=mx[i]=tag[i]=0;
		return;
	}
	inline void pushup(int now){
		mn[now]=min(mn[now*2],mn[now*2+1]);
		mx[now]=max(mx[now*2],mx[now*2+1]);
		return;
	}
	inline void pushdown(int now){
		if (tag[now]==0)return;
		tag[now*2]+=tag[now],tag[now*2+1]+=tag[now];
		mn[now*2]+=tag[now],mn[now*2+1]+=tag[now];
		mx[now*2]+=tag[now],mx[now*2+1]+=tag[now];
		tag[now]=0;
		return; 
	}
	inline void update(int now,int nowl,int nowr,int lt,int rt,int k){
		pushdown(now);
		if (nowl>=lt&&nowr<=rt){
			tag[now]+=k;
			mn[now]+=k,mx[now]+=k;
			return;
		}
		int mid=(nowl+nowr)/2;
		if (mid>=lt)update(now*2,nowl,mid,lt,rt,k);
		if (mid+1<=rt)update(now*2+1,mid+1,nowr,lt,rt,k);
		pushup(now);
		return;
	}
	inline int askmn(int now,int nowl,int nowr,int lt,int rt){
		pushdown(now);
		if (nowl>=lt&&nowr<=rt)return mn[now];
		int mid=(nowl+nowr)/2,s=2e9;
		if (mid>=lt)s=min(s,askmn(now*2,nowl,mid,lt,rt));
		if (mid+1<=rt)s=min(s,askmn(now*2+1,mid+1,nowr,lt,rt));
		return s;
	}
	inline int askmx(int now,int nowl,int nowr,int lt,int rt){
		pushdown(now);
		if (nowl>=lt&&nowr<=rt)return mx[now];
		int mid=(nowl+nowr)/2,s=0;
		if (mid>=lt)s=max(s,askmx(now*2,nowl,mid,lt,rt));
		if (mid+1<=rt)s=max(s,askmx(now*2+1,mid+1,nowr,lt,rt));
		return s;
	}
}sgt;
inline void out(){
	if (sgt.askmn(1,1,n,1,n)<0){
		printf("-1 ");
		return;
	}
	if (sgt.askmx(1,1,n,n,n)!=0){
		printf("-1 ");
		return;
	}
	printf("%d ",sgt.askmx(1,1,n,1,n));
	return; 
}
int main(){
	cin>>n;
	scanf("%s",s+1);
	sgt.mem();
	now=tot=1;
	for (int i=1;i<=n;i++){
		tot++;
		if (s[i]=='R'){
			out();
			now++;
		}
		else if (s[i]=='L'){
			out();
			now--;
			if (now<1)now=1;
		}
		else{
			tot--;
			if (a[now]=='(')sgt.update(1,1,n,now,n,-1);
			if (a[now]==')')sgt.update(1,1,n,now,n,1);
			a[now]=s[i];
			if (a[now]=='(')sgt.update(1,1,n,now,n,1);
			if (a[now]==')')sgt.update(1,1,n,now,n,-1);
			out();
		}
	}
	return 0;
}
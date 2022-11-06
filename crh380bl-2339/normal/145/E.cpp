#include<cstdio>
#include<algorithm>

const int maxn=1000000+5;
const int maxm=maxn<<2;
int rev[maxm],cnt0[maxm],cnt1[maxm],ln01[maxm],ln10[maxm];
char s[maxn],buf[32];


void pushup(int rt){
	int ls=rt<<1,rs=ls|1;
	cnt0[rt]=cnt0[ls]+cnt0[rs];
	cnt1[rt]=cnt1[ls]+cnt1[rs];
	ln01[rt]=std::max(cnt0[ls]+ln01[rs],ln01[ls]+cnt1[rs]);
	ln10[rt]=std::max(cnt1[ls]+ln10[rs],ln10[ls]+cnt0[rs]);
}
void pushdown(int rt){
	if(!rev[rt])return;
	int ls=rt<<1,rs=ls|1;
	std::swap(cnt0[ls],cnt1[ls]);
	std::swap(cnt0[rs],cnt1[rs]);
	std::swap(ln01[ls],ln10[ls]);
	std::swap(ln01[rs],ln10[rs]);
	rev[ls]^=1;
	rev[rs]^=1;
	rev[rt]=0;
}
void build(int rt,int l,int r){
	if(l==r){
		ln01[rt]=ln10[rt]=1;
		if(s[l]=='4'){
			cnt0[rt]=1;
		}
		else{
			cnt1[rt]=1;
		}
		return;
	}
	int ls=rt<<1,rs=ls|1,mid=(l+r)>>1;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(rt);
}
void upd(int rt,int l,int r,int tl,int tr){
	if(tl<=l&&r<=tr){
		rev[rt]^=1;
		std::swap(cnt0[rt],cnt1[rt]);
		std::swap(ln01[rt],ln10[rt]);
		return;
	}
	pushdown(rt);
	int ls=rt<<1,rs=ls|1,mid=(l+r)>>1;
	if(tl<=mid)upd(ls,l,mid,tl,tr);
	if(tr>mid)upd(rs,mid+1,r,tl,tr);
	pushup(rt);
}


int main(){

	int n,m;
	scanf("%d%d%s",&n,&m,s+1);
	build(1,1,n);
	while(m--){
		scanf("%s",buf);
		if(buf[0]=='s'){
			int x,y;scanf("%d%d",&x,&y);
			upd(1,1,n,x,y);
		}
		else{
			printf("%d\n",ln01[1]);
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}

#define N 1100004
#define lo(x) ((x)&(-(x)))
int s1,s2,l,r,mi,_mi,_ma,h[N],ad[N],n,ss,p[N],a[N],C,o,oo,op;
long long Ans;
inline void add(int p)
{
	for(int i=p;i<=n;i+=lo(i))++h[i];
}
inline void del(int p)
{
	for(int i=p;i<=n;i+=lo(i))--h[i];
}
inline int que(int p)
{
	int s=0;
	for(int i=p;i;i-=lo(i))s+=h[i];
	return s;
}
#define ls (p<<1)
#define rs ((p<<1)|1) 

void ins(int p, int l, int r, int x, int y)
{
	if(l>y||r<x)return;
	if(x<=l&&r<=y){
		++ad[p];
		return;
	}
	int mi=l+r>>1;
	ins(ls,l,mi,x,y);ins(rs,mi+1,r,x,y);
}

int que(int p, int l, int r, int x)
{
	if(l==r)return ad[p];
	int mi=l+r>>1;
	if(x<=mi)return ad[p]+que(ls,l,mi,x);
	return ad[p]+que(rs,mi+1,r,x);
}


int main()
{
//	freopen("1.in","r",stdin);
	n=read();
	for(int i=1;i<=n;++i)a[i]=read(),p[a[i]]=i; 
	_ma=_mi=C=p[1]; printf("0 "); add(p[1]);
	
	for(int i=2;i<=n;++i){	
	
//		if(i==50)
//		int cyb=1;
	
		op=p[i];
		Ans+=que(n)-que(op);
		add(op);
		
		if(op<_mi){
			ins(1,1,n,op,_mi);
			Ans+=_mi-op+1-(que(_mi)-que(op-1));
			
			l=op; r=_ma;
			while(l<=r){
				mi=l+r>>1;
				s1=que(mi);
				s2=que(n)-que(mi-1);
				if(s1<=s2){
					o=mi,l=mi+1;
				}else r=mi-1;
			}
			
			if(i!=2){
			
			del(op);
			l=_mi; r=_ma;
			while(l<=r){
				mi=l+r>>1;
				s1=que(mi)-que(_mi-1);
				s2=que(_ma)-que(mi-1);
				if(s2<=s1){
					oo=mi,r=mi-1;
				}else l=mi+1;
			}
			add(op); --oo;
			ins(1,1,n,_mi,oo);
			Ans+=oo-_mi+1-(que(oo)-que(_mi-1));
			
			}
			C=o;
			goto lll;
		}
		
		if(op>_ma){
			ins(1,1,n,_ma,op);
			Ans+=op-_ma+1-(que(op)-que(_ma-1));
			l=_mi; r=op;
			while(l<=r){
				mi=l+r>>1;
				s1=que(mi)-que(_mi-1);
				s2=que(op)-que(mi-1);
				if(s1<=s2){
					o=mi,l=mi+1;
				}else r=mi-1;
			}
			ins(1,1,n,C+1,_ma);
			Ans+=_ma-C-(que(_ma)-que(C));
			C=o;
			goto lll;
		}
		
		Ans-=que(1,1,n,op);
//		if(C==op)goto lll;
		l=_mi; r=_ma;
		while(l<=r){
			mi=l+r>>1;
			s1=que(mi)-que(_mi-1);
			s2=que(_ma)-que(mi-1);
			if(s1<=s2){
				o=mi,l=mi+1;
			}else r=mi-1;
		}
		if(C<o){
			ins(1,1,n,C+1,op);
			Ans+=op-C-(que(op)-que(C));
			C=o;
			goto lll;
		}
		if(C>o){
			
			del(op);
			l=_mi; r=_ma;
			while(l<=r){
				mi=l+r>>1;
				s1=que(mi)-que(_mi-1);
				s2=que(_ma)-que(mi-1);
				if(s2<=s1){
					oo=mi,r=mi-1;
				}else l=mi+1;
			}
			--oo;
			add(op);
			
			if(op<=oo){
				ins(1,1,n,op,oo);
				Ans+=oo-op+1-(que(oo)-que(op-1));
			}
			C=o;
			goto lll;
		}
		if(C==o){
			if(op<o){  // //
				ins(1,1,n,op,o);
				Ans+=o-op+1-(que(o)-que(op-1));
			} else {
				ins(1,1,n,o+1,op);
				Ans+=op-o-(que(op)-que(o));
			}
		}
		
		lll:;
		_ma=max(op,_ma);
		_mi=min(op,_mi);
		printf("%lld ",Ans);
	}
}
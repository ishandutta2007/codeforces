#include<bits/stdc++.h>
using namespace std;
int n,m,x,op,y,k;
const int maxn=1e5+100;
struct n1{int l,r,s;
n1 operator+(n1 y){return (n1){l,y.r,s+y.s};}
bool operator<(n1 y)const{return s<y.s;}};
struct node{
	n1 smax,smin,lmax,lmin,rmax,rmin,sum;
	int rev;
}t[maxn*4];
queue<node>q;
void newp(int p,int l,int k){
	t[p].smax=(n1){l,l,k};
	t[p].lmax=(n1){l,l,k};
	t[p].rmax=(n1){l,l,k};
	t[p].smin=(n1){l,l,k};
	t[p].lmin=(n1){l,l,k};
	t[p].rmin=(n1){l,l,k};
	t[p].sum=(n1){l,l,k};
}
node merge(node x,node y){
	node z;
	z.smax=max(x.smax,y.smax);
	z.smax=max(z.smax,x.rmax+y.lmax);
	z.smin=min(x.smin,y.smin);
	z.smin=min(z.smin,x.rmin+y.lmin);
	z.lmax=max(x.lmax,x.sum+y.lmax);
	z.rmax=max(y.rmax,x.rmax+y.sum);
	z.lmin=min(x.lmin,x.sum+y.lmin);
	z.rmin=min(y.rmin,x.rmin+y.sum);
	z.sum=x.sum+y.sum;
	z.rev=0;
	return z;
}
void clean(int p){
	swap(t[p].smax,t[p].smin);
	swap(t[p].lmax,t[p].lmin);
	swap(t[p].rmax,t[p].rmin);
	t[p].smax.s*=-1;
	t[p].smin.s*=-1;
	t[p].lmax.s*=-1;
	t[p].lmin.s*=-1;
	t[p].rmax.s*=-1;
	t[p].rmin.s*=-1;
	t[p].sum.s*=-1;
	t[p].rev^=1;
}
void change(int p,int l,int r,int x,int k){
	if(l==r){
		newp(p,l,k);
		return;
	}
	int mid=l+r>>1;
	if(t[p].rev){
		clean(p<<1);
		clean(p<<1|1);
		t[p].rev^=1;
	}
	if(x<=mid)change(p<<1,l,mid,x,k);
	else change(p<<1|1,mid+1,r,x,k);
	t[p]=merge(t[p<<1],t[p<<1|1]);
}
void rev(int p,int l,int r,int x,int y){
    if((l==x)&&(r==y)){clean(p);return;}
    int mid=l+r>>1;
    if (t[p].rev){
        clean(p<<1);
        clean(p<<1|1);
        t[p].rev^=1;
    }
    if(y<=mid)rev(p<<1,l,mid,x,y);
    else if(x>mid)rev(p<<1|1,mid+1,r,x,y);
    else{
        rev(p<<1,l,mid,x,mid);
        rev(p<<1|1,mid+1,r,mid+1,y);
    }
    t[p]=merge(t[p<<1],t[p<<1|1]);
}
node query(int p,int l,int r,int x,int y){
    if((l==x)&&(r==y))return t[p];
    int mid=l+r>>1;
    if(t[p].rev){
        clean(p<<1);
        clean(p<<1|1);
        t[p].rev^=1;
    }
    if (y<=mid) return query(p*2,l,mid,x,y);
    else if (x>mid) return query(p*2+1,mid+1,r,x,y);
    else
    {
        return merge(query(p*2,l,mid,x,mid),query(p*2+1,mid+1,r,mid+1,y));
    }
}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x),change(1,1,n,i,x);
	scanf("%d",&m);
	while(m--){
		scanf("%d",&op);
		if(op==0){
			scanf("%d%d",&x,&k);
			change(1,1,n,x,k);
		}else{
			scanf("%d%d%d",&x,&y,&k);
			int ans=0;while(k--){
				node d=query(1,1,n,x,y);
				if(d.smax.s<0)break;
				ans+=d.smax.s;
				rev(1,1,n,d.smax.l,d.smax.r);
				q.push(d);
			}
            printf("%d\n",ans);
            while (!q.empty())
            {
                node d=q.front();
                q.pop();
                rev(1,1,n,d.smax.l,d.smax.r);
            }
		}
	} 
}
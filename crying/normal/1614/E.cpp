#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=2e5+10,LIM=1e9+1,mod=1e9+1; 
int n,k,a[MAXN],ans,rt;
vector<int>q[MAXN];
struct Node{
	int lc,rc,sum;
};
struct Seg{
	Node t[(int)1e7+10];
	int tot;
	void pushup(int x){t[x].sum=t[t[x].lc].sum+t[t[x].rc].sum;}
	void update(int x,int l,int r,int pos,int val){
		if(l==r){
			t[x].sum+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(pos<=mid){
			if(!t[x].lc)t[x].lc=++tot;
			update(t[x].lc,l,mid,pos,val);
		}else{
			if(!t[x].rc)t[x].rc=++tot;
			update(t[x].rc,mid+1,r,pos,val);
		} 
		pushup(x);
	}
	int qry(int x,int l,int r,int ql,int qr){
		if(ql<=l && qr>=r)return t[x].sum;
		int mid=(l+r)>>1;int ret=0;
		if(ql<=mid)ret+=qry(t[x].lc,l,mid,ql,qr);
		if(qr>mid)ret+=qry(t[x].rc,mid+1,r,ql,qr);
		return ret; 
	}
	int F1(int x,int L,int R,int k){
		if(L==R){
			if(L-1+t[x].sum==k)return L;
			else return -1;
		}
		int mid=(L+R)>>1;
		if(mid-1+t[t[x].lc].sum>=k)return F1(t[x].lc,L,mid,k);
		else return F1(t[x].rc,mid+1,R,k-t[t[x].lc].sum);
	} 
	void F2(int x,int L,int R,int k,int& val){
		if(L==R){
			if(L-1+t[x].sum==k)val=max(val,L);
			return;
		}
		int mid=(L+R)>>1;
		if(mid-1+t[t[x].lc].sum>k)F2(t[x].lc,L,mid,k,val);
		else if(mid-1+t[t[x].lc].sum<k)F2(t[x].rc,mid+1,R,k-t[t[x].lc].sum,val);
		else{
			if(mid-1+t[t[x].lc].sum==k)val=max(val,mid);
			F2(t[x].rc,mid+1,R,k-t[t[x].lc].sum,val);
		}
	}
}t;
void upd(int L,int R,int val){
	t.update(rt,1,LIM,L,val);
	if(R!=LIM)t.update(rt,1,LIM,R+1,-val);
}
int qry(int pos){
	int ret=t.qry(rt,1,LIM,1,pos);
	return ret;
}
int main(){
	rt=++t.tot;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d%d",&a[i],&k);
		rep(j,1,k){
			int tmp;scanf("%d",&tmp);
			q[i].push_back(tmp);
		}
	}
	rep(i,1,n){
		int L=0,R=0,r1=-1,r2=-1;
		int minn=0+qry(1),maxn=LIM-1+qry(LIM);
		//find first = a[i]
		/*
		L=1,R=1e9+1;
		while(L<=R){
			int mid=(L+R)>>1;
			ll val=mid-1+qry(mid);
			if(val==a[i]){
				r1=mid;
				R=mid-1;
			}else if(val<a[i]){
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		*/
		r1=t.F1(1,1,LIM,a[i]);
		t.F2(1,1,LIM,a[i],r2);
		/*
		//find last = a[i]
		L=1,R=1e9+1;
		while(L<=R){
			int mid=(L+R)>>1;
			ll val=mid-1+qry(mid);
			if(val==a[i]){
				r2=mid;
				L=mid+1;
			}else if(val<a[i]){
				L=mid+1;
			}else{
				R=mid-1;
			}
		}
		*/
		
		if(maxn<a[i]){
			t.update(1,1,LIM,1,1);
		}
		else if(minn>a[i]){
			t.update(1,1,LIM,1,-1);
		}else{
			if(r1!=1){
				t.update(1,1,LIM,1,1);
				t.update(1,1,LIM,r1,-1);
			}
			if(r2!=LIM)t.update(1,1,LIM,r2+1,-1);
		}
		for(auto v:q[i]){
			int val=(v+ans)%mod;
			ans=val+qry(val+1);
			printf("%d\n",ans);
		}
	}

	return 0;
}
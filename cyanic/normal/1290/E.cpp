#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se seoncd
#define pb push_back
#define mp make_pair
#define lc (o<<1)
#define rc (o<<1|1)
#define mid ((l+r)>>1)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=300005;
struct seg{
	int mx[N<<2],T[N<<2],c[N<<2];
	int calc(int o,int l,int r,int val){
		if(l==r)return mx[o]>val;
		if(val<mx[lc])return T[o]+calc(lc,l,mid,val);
		return calc(rc,mid+1,r,val);
	}
	void upd(int o,int l,int r,int x,int val){
		if(l==r){mx[o]=val,c[o]++;return;}
		if(x<=mid)upd(lc,l,mid,x,val);
		else upd(rc,mid+1,r,x,val);
		mx[o]=max(mx[lc],mx[rc]);
		T[o]=calc(rc,mid+1,r,mx[lc]);
		c[o]=c[lc]+c[rc];
	}
	int qry(int o,int l,int r,int x,int y,int &ret){
		if(x>y||r<x||y<l) return 0;
		if(l==x&&y==r){
			int res=calc(o,l,r,ret);
			return ret=max(ret,mx[o]),res;
		}
		if(y<=mid)return qry(lc,l,mid,x,y,ret);
		if(mid<x)return qry(rc,mid+1,r,x,y,ret);
		int res=qry(lc,l,mid,x,mid,ret);
		return res+qry(rc,mid+1,r,mid+1,y,ret);		
	}
	int count(int o,int l,int r,int x,int y){
		if(x>y||r<x||y<l) return 0;
		if(l==x&&y==r) return c[o];
		if(y<=mid)return count(lc,l,mid,x,y);
		if(mid<x)return count(rc,mid+1,r,x,y);
		int res=count(lc,l,mid,x,mid);
		return res+count(rc,mid+1,r,mid+1,y);	
	}
	int Find(int o,int l,int r,int x,int val){
		if(x>r) return 0;
		if(x<=l&&mx[o]<val) return 0;
		if(l==r) return l;
		int ret=(x<=mid?Find(lc,l,mid,x,val):0);
		return ret?ret:Find(rc,mid+1,r,x,val);
	}
} L,R;
int a[N],p[N],n;
vi pre,suf;
ll ans;

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		p[a[i]]=i;
	}
	rep(i,1,n){
//		printf("p[%d] = %d\n",i,p[i]);
		int l=p[i],r=p[i],flag=-1;
		pre.clear();
		suf.clear();
		for(;;){
			int vl=(l==p[i]?1:a[l]);
			int vr=(r==p[i]?1:a[r]);
			l=n+1-L.Find(1,1,n,n+1-l+1,vl);
			r=R.Find(1,1,n,r+1,vr);
			if(!r) { flag=1; break; }
			if(l==n+1) { flag=0; break; }
//			printf("%d %d\n",l,r);
			pre.pb(l),suf.pb(r);
		}
//		cout<<"#"<<flag<<endl;
		if(flag){
			suf.pb(n+1);
			int sz=suf.size()-1;
//			printf("@@@ %d\n",sz);
			REP(j,sz){
				int cr=R.count(1,1,n,suf[j],suf[j+1]-1);
				int pos=n+1-L.Find(1,1,n,n+1-p[i],a[suf[j]]);
				if(pos==n+1){
					ans-=R.count(1,1,n,1,p[i]);
					continue;
				}
				ans-=R.count(1,1,n,pos+1,p[i]);
				int tmp=a[suf[j]];
				ans-=(ll)cr*L.qry(1,1,n,n+1-pos,n,tmp);
			}
		}
		else{
			pre.pb(0);
			int sz=pre.size()-1;
			REP(j,sz){
				int cl=R.count(1,1,n,pre[j+1]+1,pre[j]);
				int pos=R.Find(1,1,n,p[i],a[pre[j]]);
//				printf("## %d %d %d\n",p[i],a[pre[j]],pos);
				if(pos==0){
					ans-=R.count(1,1,n,p[i],n);
					continue;
				}
				ans-=R.count(1,1,n,p[i],pos-1);
				int tmp=a[pre[j]];
				ans-=(ll)cl*R.qry(1,1,n,pos,n,tmp);
			}
		}
		L.upd(1,1,n,n+1-p[i],i);
		R.upd(1,1,n,p[i],i);
		printf("%lld\n",ans+=i);
	}
	return 0;
}
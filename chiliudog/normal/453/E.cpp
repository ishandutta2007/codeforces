#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=200005;
int n,Q,s[maxn],m[maxn],t[maxn],l[maxn],r[maxn],R[maxn];
typedef pair<pin,int> info;
set<info> res;
typedef set<info>::iterator It;
namespace seg{
	i64 suma[maxn<<5],sumb[maxn<<5];
	int ls[maxn<<5],rs[maxn<<5],tot;
	inline void update(int x){
		suma[x]=suma[ls[x]]+suma[rs[x]];
		sumb[x]=sumb[ls[x]]+sumb[rs[x]];
	}
	inline void add(int x,int &y,int place,int va,int vb,int l,int r){
		y=++tot;suma[y]=suma[x];sumb[y]=sumb[x];ls[y]=ls[x];rs[y]=rs[x];
		suma[y]+=va;sumb[y]+=vb;
		if(l==r){
			//suma[x]+=va;sumb[x]+=vb;
			return;
		}int md=(l+r)>>1;
		if(place<=md)
			add(ls[x],ls[y],place,va,vb,l,md);
		else
			add(rs[x],rs[y],place,va,vb,md+1,r);
	}
	inline i64 queryA(int x,int l,int r,int lq,int rq){
		if(!x)return 0;
		if(lq<=l&&r<=rq)return suma[x];
		i64 res=0;int md=(l+r)>>1;
		if(lq<=md)res+=queryA(ls[x],l,md,lq,rq);
		if(rq> md)res+=queryA(rs[x],md+1,r,lq,rq);
		return res;
	}
	inline i64 queryB(int x,int l,int r,int lq,int rq){
		if(!x)return 0;
		if(lq<=l&&r<=rq)return sumb[x];
		i64 res=0;int md=(l+r)>>1;
		if(lq<=md)res+=queryB(ls[x],l,md,lq,rq);
		if(rq> md)res+=queryB(rs[x],md+1,r,lq,rq);
		return res;
	}
}
int qtot=0;
int root[maxn];
inline i64 query(int l,int r,int tme){
	tme=min(tme,99999);
	return seg::queryA(root[r],0,100001,0,tme)-seg::queryA(root[l-1],0,100001,0,tme)+
		   1ll*(seg::queryB(root[r],0,100001,tme+1,100001)-seg::queryB(root[l-1],0,100001,tme+1,100001))*tme;
}
int main(){
    read(n);
    rep(i,1,n)read(s[i]),read(m[i]),read(R[i]);
    rep(i,1,n)res.insert(mk(mk(i,i),-1));
//    rep(i,1,n)if(m[i]==5450)fprintf(stderr,"%d ",i);fprintf(stderr,"\n");
 	//fprintf(stderr,"%d %d %d\n",s[39],m[39],R[39]);
    read(Q);
    rep(i,1,Q)read(t[i]),read(l[i]),read(r[i]);
    rep(i,1,n){
    	if(R[i]==0){
    		seg::add(root[i-1],root[i],100001,0,R[i],0,100001);
    		continue;
    	}//assert(m[i]!=0);
    	int t=floor((long double)m[i]/R[i]+0.99999999);
    	//if(i==39)fprintf(stderr,"%d\n",t);
    	assert(1ll*t*R[i]>=m[i]);
    	assert(1ll*(t-1)*R[i]<m[i]);
    	seg::add(root[i-1],root[i],t,m[i],R[i],0,100001);
    }
    rep(i,1,Q){
    	i64 ans=0;
    	//if(i==82259)fprintf(stderr,"%d %d %d\n",l[i],r[i],t[i]);
    	//if(i==82259)fprintf(stderr,"?%d\n",m[10]);
    	It it=res.upper_bound(mk(mk(l[i],n+1),1));
    	vector<It> rubi;rubi.clear();
    	it--;
    	if(it->w1.w1<l[i]){
    		res.insert(mk(mk(it->w1.w1,l[i]-1),it->w2));
    	}
    	int tmp1=it->w1.w2,tmp2=it->w2;
    	res.erase(it);
    	res.insert(mk(mk(l[i],tmp1),tmp2));
    	it=res.upper_bound(mk(mk(l[i],n+1),1));
    	it--;
    	for(;;){
    		//if(it==res.end())break;
    	//	if(i==82259)fprintf(stderr,"%d %d %d\n",it->w1.w1,it->w1.w2,it->w2);
    		if(it->w2==-1){
   	 			assert(it->w1.w1==it->w1.w2);
    			ans+=min((i64)m[it->w1.w1],(i64)s[it->w1.w1]+1ll*R[it->w1.w1]*t[i]);
    		}
    		else{
    			ans+=query(it->w1.w1,min(it->w1.w2,r[i]),t[i]-it->w2);
    	//		if(i==82259)fprintf(stderr,"* %lld\n",query(it->w1.w1,min(it->w1.w2,r[i]),t[i]-it->w2));
    			i64 res=0;
    		//	if(i==82259){
    		//		rep(k,it->w1.w1,min(r[i],it->w1.w2))
    		//			res+=min((i64)m[k],1ll*R[k]*(t[i]-it->w2));
    		//		fprintf(stderr,"& %lld\n",res);
    		//	}
    		}
    		rubi.pb(it);
    		if(it->w1.w2>r[i]){
    			res.insert(mk(mk(r[i]+1,it->w1.w2),it->w2));
    			break;
    		}
    		if(it->w1.w2==r[i])break;
    		it++;
    	}
    	for(It x:rubi)res.erase(x);
    	res.insert(mk(mk(l[i],r[i]),t[i]));
    	cout<<ans<<endl;
    //	if(i==82259)fprintf(stderr,"?%lld\n",ans);
    }

    return 0;
}
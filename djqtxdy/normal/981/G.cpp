#include<bits/stdc++.h>
#define LL long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define big 20160116
#define INF 2147483647
#define pq priority_queue
#define rank rk124232
#define y1 y20160116
#define y0 y20160110
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
namespace Mymath{
	LL qp(LL x,LL p,LL mod){
		LL ans=1;
		while (p){
			if (p&1) ans=ans*x%mod;
			x=x*x%mod;
			p>>=1;
		}
		return ans;
	}
	LL inv(LL x,LL mod){
		return qp(x,mod-2,mod);
	}
	LL C(LL N,LL K,LL fact[],LL mod){
		return fact[N]*inv(fact[K],mod)%mod*inv(fact[N-K],mod)%mod;
	}
	template <typename Tp> Tp gcd(Tp A,Tp B){
		if (B==0) return A;
		return gcd(B,A%B);
	}
	template <typename Tp> Tp lcm(Tp A,Tp B){
		return A*B/gcd(A,B);
	}
};
namespace fwt{
	using namespace Mymath;
	void FWT(int a[],int n,LL mod)
	{
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=(x+y)%mod,a[i+j+d]=(x-y+mod)%mod;
	                //xor:a[i+j]=x+y,a[i+j+d]=x-y;
	                //and:a[i+j]=x+y;
	                //or:a[i+j+d]=x+y;
	            }
	}

	void UFWT(int a[],int n,LL mod)
	{
		LL rev=inv(2,mod);
	    for(int d=1;d<n;d<<=1)
	        for(int m=d<<1,i=0;i<n;i+=m)
	            for(int j=0;j<d;j++)
	            {
	                int x=a[i+j],y=a[i+j+d];
	                a[i+j]=1LL*(x+y)*rev%mod,a[i+j+d]=(1LL*(x-y)*rev%mod+mod)%mod;
	                //xor:a[i+j]=(x+y)/2,a[i+j+d]=(x-y)/2;
	                //and:a[i+j]=x-y;
	                //or:a[i+j+d]=y-x;
	            }
	}
	void solve(int a[],int b[],int n,LL mod)
	{
	    FWT(a,n,mod);
	    FWT(b,n,mod);
	    for(int i=0;i<n;i++) a[i]=1LL*a[i]*b[i]%mod;
	    UFWT(a,n,mod);
	}
};
const int Maxn=2e5+5;
const LL mod=998244353;
int n,q;
LL tag1[Maxn*4],tag2[Maxn*4];
LL tree[Maxn*4];
void Push(int p,int l,int r){
	//cout<<"Push"<<' '<<p<<' '<<tag1[p]<<endl; 
	tag1[p*2]=tag1[p]*tag1[p*2]%mod;
	tree[p*2]=tree[p*2]*tag1[p]%mod;
	tag1[p*2+1]=tag1[p]*tag1[p*2+1]%mod;
	tree[p*2+1]=tree[p*2+1]*tag1[p]%mod;
	tag2[p*2]=tag2[p*2]*tag1[p]%mod;
	tag2[p*2+1]=tag2[p*2+1]*tag1[p]%mod;
	tag1[p]=1;
	int mid=l+r>>1;
	tag2[p*2]=(tag2[p*2]+tag2[p])%mod;
	tree[p*2]=(tree[p*2]+tag2[p]*(mid-l+1))%mod;
	tag2[p*2+1]=(tag2[p*2+1]+tag2[p])%mod;
	tree[p*2+1]=(tree[p*2+1]+tag2[p]*(r-mid))%mod;
	tag2[p]=0;
}
void Add(LL &x,LL y){
	x+=y;
	if (x>=mod) x-=mod;
}
void modify1(int p,int l,int r,int lo,int hi){
	/*
	if (p==1){
		cout<<"MUL"<<' '<<lo<<' '<<hi<<endl;
	}*/
	if (lo>hi) return;
	if (lo<=l && r<=hi){
		Add(tree[p],tree[p]);
		Add(tag2[p],tag2[p]);
		Add(tag1[p],tag1[p]);
		return;
	}
	Push(p,l,r);
	int mid=l+r>>1;
	if (lo<=mid){
		modify1(p*2,l,mid,lo,min(hi,mid));
	} 
	if (hi>mid){
		modify1(p*2+1,mid+1,r,max(lo,mid+1),hi);
	}
	tree[p]=(tree[p*2]+tree[p*2+1])%mod;
}
void modify2(int p,int l,int r,int lo,int hi,LL v){
	v=1;
	/*
	if (p==1){
		cout<<"Add"<<' '<<lo<<' '<<hi<<' '<<v<<endl;
	}*/
	if (lo>hi) return;
	if (lo<=l && r<=hi){
		Add(tree[p],v*(r-l+1)%mod);
		Add(tag2[p],v);
		return;
	}
	Push(p,l,r);
	int mid=l+r>>1;
	if (lo<=mid){
		modify2(p*2,l,mid,lo,min(hi,mid),v);
	} 
	if (hi>mid){
		modify2(p*2+1,mid+1,r,max(lo,mid+1),hi,v);
	}
	tree[p]=(tree[p*2]+tree[p*2+1])%mod;
}
LL query(int p,int l,int r,int lo,int hi){
	if (lo<=l && r<=hi){
		return tree[p];
	}
	Push(p,l,r);
	int mid=l+r>>1;
	LL ret=0;
	if (lo<=mid){
		Add(ret,query(p*2,l,mid,lo,min(hi,mid)));
	}
	if (hi>mid){
		Add(ret,query(p*2+1,mid+1,r,max(lo,mid+1),hi));
	}
	return ret;
}
set<pair<int,int> > S[Maxn];
int main(){
	n=read();q=read();
	for (int i=0;i<4*Maxn;i++) tag1[i]=1;
	while (q--){
		int tp=read();
		if (tp==1){
			int l,r;
			LL v;
			l=read();r=read();v=read();
			if (S[v].empty()){
				modify2(1,1,n,l,r,v);
				S[v].insert(mp(r,l));
				continue;
			}
			set<pair<int,int> >::iterator it=S[v].lower_bound(mp(l,0)),it2;
			if (it==S[v].end()){
				modify2(1,1,n,l,r,v);
				S[v].insert(mp(r,l));
				continue;
			}
			pair<int,int> vi=*it;
			swap(vi.first,vi.second);
		//	cout<<"f"<<' '<<it->first<<' '<<it->second<<endl;
			if (vi.second<l){
				it++;
			}
			if (it==S[v].end() || it->second>r){
				modify2(1,1,n,l,r,v);
				S[v].insert(mp(r,l));
				continue;
			}
			vi=*it;
			swap(vi.first,vi.second);
			if (vi.first>l){
				modify2(1,1,n,l,vi.first-1,v);
			}
			int bbg=min(vi.first,l);
			int eed;
			//cout<<"FERR"<<endl; 
			while (1){
				int beg=max(vi.first,l),ed=min(vi.second,r);
				modify1(1,1,n,beg,ed);
				if (ed==r){
					eed=it->first;
					S[v].erase(it);
					
					break;
				}
				int nxt=r;
				it2=it;
				it++;
				S[v].erase(it2);
				if (it!=S[v].end() && it->second<=r){
					nxt=it->second-1;
					modify2(1,1,n,ed+1,nxt,v);
				}
				else{
					eed=r;
					modify2(1,1,n,ed+1,nxt,v);
					break;
				}
				vi=*it;
				swap(vi.first,vi.second);
			}
		//	cout<<"range"<<' '<<bbg<<' '<<eed<<endl;
			S[v].insert(mp(eed,bbg));
			//cout<<eed<<' '<<bbg<<endl;
		//	cout<<"Siz"<<' '<<S[v].size()<<endl;
		}
		else{
			int l,r;
			l=read();r=read();
			printf("%I64d\n",query(1,1,n,l,r));
		}
	}
	return 0;
}
/*
3 6
1 1 2 1
1 2 3 1
1 1 3 1
2 1 3
1 1 3 1 
2 1 3
*/
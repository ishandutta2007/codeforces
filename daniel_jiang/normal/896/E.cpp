// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back

using namespace std;
typedef long long ll;

template <typename T> void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(int x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}

inline int mx(int x,int y){return x<y?y:x;}
inline int mn(int x,int y){return x<y?x:y;}

// ---------- IO ---------- //

const int N=1e6+5,M=5e5+5,A=1e5+5;
int n,m,a[N],len,tot,maxn,l,r,ans[N],tag,cnt[N],qwq;
struct Question{int op,l,r,x;}q[N];

// ---------- Containers ---------- //

int fa[N],sum[N],rt[N],v[N];  // rt[i]  i  / fa[i]  i  / v[i]  rt   

inline int found(int x){return fa[x]==x?x:fa[x]=found(fa[x]);}

inline void merge(int x,int y){
	if(rt[y]) fa[rt[x]]=rt[y];
	else v[rt[y]=rt[x]]=y;
	cnt[y]+=cnt[x];rt[x]=cnt[x]=0;
} // x  y  

// ---------- DSU ---------- //

inline int block(int x){return (x-1)/len+1;}
inline int L(int x){return (x-1)*len+1;}
inline int R(int x){return x*len;}

inline void init(){
	maxn=tag=0;
	memset(rt,0,sizeof(rt));memset(cnt,0,sizeof(cnt));
	for(re i=l;i<=r;++i){
		maxn=mx(maxn,a[i]);cnt[a[i]]++;
		if(rt[a[i]]) fa[i]=rt[a[i]]; 
		else rt[v[i]=a[i]]=fa[i]=i;
	}
}

inline void modify(int x){
	if(maxn-tag<=(x<<1)){
		for(re i=maxn;i>tag+x;i--)
			if(rt[i]) merge(i,i-x);
		maxn=mx(tag+x,maxn);
	}
	else{
		for(re i=tag+1;i<=tag+x;++i)
			if(rt[i]) merge(i,i+x);
		tag+=x;
	}
}

inline void reconstruct(int L,int R,int x){
	for(re i=l;i<=r;++i) rt[a[i]=v[found(i)]]=cnt[v[found(i)]]=0,a[i]-=tag;
	for(re i=l;i<=r;++i) v[i]=0;tag=maxn=0;
	qwq=mn(r,R);
	for(re i=mx(l,L);i<=qwq;++i)
		if(a[i]>x) a[i]-=x;
	for(re i=l;i<=r;++i){
		maxn=mx(maxn,a[i]);cnt[a[i]]++;
		if(rt[a[i]]) fa[i]=rt[a[i]]; 
		else rt[v[i]=a[i]]=fa[i]=i;
	}
}

inline void query(int L,int R,int x,int qaq){
	if(x+tag>=N) return ;
	if(L<=l&&R>=r) ans[qaq]+=cnt[x+tag];
	else{
		qwq=mn(r,R);
		for(re i=mx(l,L);i<=qwq;++i)
			if(v[found(i)]==x+tag) ans[qaq]++;
	}
}

// ---------- Sqrt & Operations ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);rd(m);len=850;tot=block(n);
	for(re i=1;i<=n;++i) rd(a[i]);
	for(re i=1;i<=m;++i) rd(q[i].op),rd(q[i].l),rd(q[i].r),rd(q[i].x);
	for(re i=1;i<=tot;++i){
		l=L(i),r=mn(R(i),n);
		//init();
		
		maxn=tag=0;
		memset(rt,0,sizeof(rt));memset(cnt,0,sizeof(cnt));
		for(re i=l;i<=r;++i){
			maxn=mx(maxn,a[i]);cnt[a[i]]++;
			if(rt[a[i]]) fa[i]=rt[a[i]]; 
			else rt[v[i]=a[i]]=fa[i]=i;
		}
	
	//	cout<<l<<' '<<r<<endl;
		for(re j=1;j<=m;++j){
			if(r<q[j].l||q[j].r<l) continue;
			if(q[j].op==1){
				if(q[j].l<=l&&q[j].r>=r){
					//modify(q[j].x);
					int x=q[j].x;
					if(maxn-tag<=(x<<1)){
						for(re i=maxn;i>tag+x;i--)
							if(rt[i]) merge(i,i-x);
						maxn=mn(tag+x,maxn);  //  
					}
					else{
						for(re i=tag+1;i<=tag+x;++i)
							if(rt[i]) merge(i,i+x);
						tag+=x;
					}
				
				}
				else{
					//reconstruct(q[j].l,q[j].r,q[j].x);
					int L=q[j].l,R=q[j].r,x=q[j].x;
					for(re i=l;i<=r;++i) rt[a[i]=v[found(i)]]=cnt[v[found(i)]]=0,a[i]-=tag;
					for(re i=l;i<=r;++i) v[i]=0;tag=maxn=0;
					qwq=mn(r,R);
					for(re i=mx(l,L);i<=qwq;++i)
						if(a[i]>x) a[i]-=x;
					for(re i=l;i<=r;++i){
						maxn=mx(maxn,a[i]);cnt[a[i]]++;
						if(rt[a[i]]) fa[i]=rt[a[i]]; 
						else rt[v[i]=a[i]]=fa[i]=i;
					}
					
				}
			}
			else{
				//query(q[j].l,q[j].r,q[j].x,j);
				int L=q[j].l,R=q[j].r,x=q[j].x,qaq=j;
				if(x+tag>=N) continue;
				if(L<=l&&R>=r) ans[qaq]+=cnt[x+tag];
				else{
					qwq=mn(r,R);
					for(re i=mx(l,L);i<=qwq;++i)
						if(v[found(i)]==x+tag) ans[qaq]++;
				}
				
			}
	//		cout<<tag<<endl;
	//		for(re k=l;k<=r;k++) cout<<v[found(k)]<<' ';cout<<endl;
		}
	}
	for(re i=1;i<=m;++i) if(q[i].op==2) wr(ans[i]),puts("");
	return 0;
}

// ---------- Main ---------- //
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
struct H{	
	static const int M=1<<21;
	struct Node{
		int nxt; array<int,5> key;
		int val;
	}list[N*32];
	int head[M+5],top;
	H(){ memset(head,-1,sizeof(head)),top=-1; }
	inline int hash(const array<int,5>& a){
		int key=0;
		for(int i=0;i<5;++i)
			key=key*239+a[i];
//		cerr<<(key&(M-1))<<endl;
		return key&(M-1);
	}
	void add(const array<int,5>& a,int k){
		int pos=hash(a);
		for(int j=head[pos];~j;j=list[j].nxt){
			if(list[j].key==a){
				list[j].val+=k;
				return;
			}
		}
		list[++top]=(Node){head[pos],a,k};
		head[pos]=top; 
	}
	int query(const array<int,5>& a){
		for(int j=head[hash(a)];~j;j=list[j].nxt){
			if(list[j].key==a)
				return list[j].val;
		}
		return 0;
	}
}mp;
struct K{ 
	array<int,5> v;
	int x;
}a[N];
int n,m;
bool cmp(K x,K y){ return x.x<y.x; }
int popcount(int x){
	if(x==0) return 0;
	return 1+popcount(x-(x&-x));
}
array<int,5> to_v(const array<int,5>& a,int sta){
	array<int,5> b; int top=0;
	fill(b.begin(),b.end(),0);
	for(int j=0;j<m;++j)
		if((sta>>j)&1)
			b[top++]=a[j];
	return b;
}
bool check(int i){
	int cnt=0;
	for(int sta=0;sta<1<<m;++sta){
		cnt+=(popcount(sta)&1?-1:1)*mp.query(to_v(a[i].v,sta));
	}	
	return cnt!=0;
}
int main(){
	scanf("%d%d",&n,&m);
	int top=0;
	for(int i=1;i<=n;++i){
		array<int,5> b;
		fill(b.begin(),b.end(),0);
		for(int j=0;j<m;++j)
			scanf("%d",&b[j]);
		int w; scanf("%d",&w);
		sort(b.begin(),b.begin()+m);
		bool flag=0;
		for(int j=0;j+1<m;++j)
			if(b[j]==b[j+1]) {
				flag=1;
			}
		if(!flag){
			a[++top]=(K){b,w};
		}
	}
	n=top;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;++i){
		for(int sta=0;sta<1<<m;++sta){
			mp.add(to_v(a[i].v,sta),1);
		}
	}
	int ans=-1,right=n;
	for(int i=1;i<=n;++i){
		while(right>0&&check(i)){
			for(int sta=0;sta<1<<m;++sta)
				mp.add(to_v(a[right].v,sta),-1);
			--right;
		}
		if(right+1!=n+1){
			int key=a[i].x+a[right+1].x;
			if(ans==-1||key<ans) ans=key;
		}
	}
	printf("%d\n",ans);
	return 0;
}
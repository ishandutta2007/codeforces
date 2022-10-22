/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ppb pop_back
const int N=300000,DB_SZ=550;
int n,m;
bool shifted[N+1];
int mx[N+1];
struct dvdblk{
	int sz,blk_sz,in[N+1];
	struct block{int l,r;deque<int> q;}blk[DB_SZ];
	#define l(p) blk[p].l
	#define r(p) blk[p].r
	#define q(p) blk[p].q
	void blk_init(int p,int l,int r){
		l(p)=l;r(p)=r;
		for(int i=l;i<=r;i++)q(p).pb(i),in[i]=p;
	}
	void init(){
		sz=sqrt(n);blk_sz=n/sz;
		r(0)=0;
		for(int i=1;i<=sz+1;i++)blk_init(i,r(i-1)+1,min(n,r(i-1)+blk_sz));
		if(l(sz+1)<=r(sz+1))sz++;
	}
	void shift(int v){
		int p=in[v];
		deque<int>::iterator fd=find(q(p).begin(),q(p).end(),v);
		mx[v]=max(mx[v],blk_sz*(p-1)+(fd-q(p).begin()+1));
		in[v]=1;q(p).erase(fd);q(1).pf(v);
		for(int i=1;i<p;i++)in[q(i).back()]++,q(i+1).pf(q(i).back()),q(i).ppb();
//		for(int i=1;i<=sz;i++)for(int j=0;j<q(i).size();j++)cout<<q(i)[j]<<" ";puts(",");
//		for(int i=1;i<=n;i++)cout<<in[i]<<" ";puts("");
	}
	void final(){
		int cnt=0;
		for(int i=1;i<=sz;i++)for(int j=0;j<q(i).size();j++)
			mx[q(i)[j]]=max(mx[q(i)[j]],++cnt);
	}
}db;
int main(){
	cin>>n>>m;
	db.init();
	while(m--){
		int x;
		scanf("%d",&x);
		shifted[x]=true;
		db.shift(x);
	}
	db.final();
	for(int i=1;i<=n;i++)printf("%d %d\n",shifted[i]?1:i,mx[i]);
	return 0;
}
/*1
5 4
3 5 1 4
*/
/*2
4 3
1 2 4
*/
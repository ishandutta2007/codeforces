#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define ppb pop_back()
int qu;////////////will be deleted
const int N=100000,BLKN=350;
int n;
int a[N+1];
struct sqrt_bf{
	int blkn;
	int in[N+1];
	struct block{int l,r,c[N+1];deque<int> q;}blk[BLKN+1];
	#define l(p) blk[p].l
	#define r(p) blk[p].r
	#define c(p) blk[p].c
	#define q(p) blk[p].q
	void init(){
		blkn=sqrt(n);
		r(0)=0;
		for(int i=1;i<=blkn;i++){
			l(i)=r(i-1)+1;r(i)=l(i)+n/blkn-1;
			memset(c(i),0,sizeof(c(i)));
			for(int j=l(i);j<=r(i);j++)in[j]=i,c(i)[a[j]]++,q(i).pb(a[j]);
		}
		if(r(blkn)<n){
			blkn++;
			l(blkn)=r(blkn-1)+1;r(blkn)=n;
			memset(c(blkn),0,sizeof(c(blkn)));
			for(int j=l(blkn);j<=n;j++)in[j]=blkn,c(blkn)[a[j]]++,q(blkn).pb(a[j]);
		}
	}
	void chg(int l,int r){
		int lb=in[l],rb=in[r];
		if(lb==rb){
			int las=q(lb)[r-l(lb)];
			q(lb).erase(q(lb).begin()+(r-l(lb)));
			q(lb).insert(q(lb).begin()+(l-l(lb)),las);
		}
		else{
			for(int i=lb;i<rb;i++){
				c(i)[q(i).back()]--;
				c(i+1)[q(i).back()]++;
				q(i+1).pf(q(i).back());
				q(i).ppb;
			}
			int las=q(rb)[r+1-l(rb)];
			c(rb)[las]--;
			c(lb)[las]++;
			q(lb).insert(q(lb).begin()+(l-l(lb)),las);
			q(rb).erase(q(rb).begin()+(r+1-l(rb)));
		}
	}
	int ask(int l,int r,int v){
		int lb=in[l],rb=in[r];
		int res=0;
		if(lb==rb)for(int i=l-l(lb);i<=r-l(lb);i++)res+=q(lb)[i]==v;
		else{
			for(int i=l-l(lb);i<=r(lb)-l(lb);i++)res+=q(lb)[i]==v;
			for(int i=lb+1;i<rb;i++)res+=c(i)[v];
			for(int i=0;i<=r-l(rb);i++)res+=q(rb)[i]==v;
		}
		return res;
	}
}sbf;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	sbf.init();
//	int qu;
	scanf("%d",&qu);
	int lasans=0;
	while(qu--){
		int tp,x,y,z;
		scanf("%d%d%d",&tp,&x,&y);
		x=(x+lasans-1)%n+1;y=(y+lasans-1)%n+1;if(x>y)swap(x,y);
		if(tp==1)sbf.chg(x,y);
		else scanf("%d",&z),z=(z+lasans-1)%n+1,printf("%d\n",lasans=sbf.ask(x,y,z));
	}
	return 0;
}
/*1
7
6 6 2 7 4 2 5
7
1 3 6
2 2 4 2
2 2 4 7
2 2 2 5
1 2 6
1 1 4
2 1 7 3
*/
/*2
8
8 4 2 2 7 7 8 8
8
1 8 8
2 8 1 7
1 8 1
1 7 3
2 8 8 3
1 1 4
1 2 7
1 4 5
*/
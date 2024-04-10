#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;
#define R register int
#define L long long
#define I inline
struct Spell{
	int type,d;
}s[200000];
class SegmentTree{
	int tot[800000];
	L sum[800000];
	public:
		I void Modify(int p,int lf,int rt,int x,int d,int s){
			if(lf==rt){
				tot[p]+=d;
				sum[p]+=s;
				return;
			}
			int mid=lf+rt>>1;
			if(x>mid){
				Modify(p<<1|1,mid+1,rt,x,d,s);
			}else{
				Modify(p<<1,lf,mid,x,d,s);
			}
			tot[p]=tot[p<<1]+tot[p<<1|1];
			sum[p]=sum[p<<1]+sum[p<<1|1];
		}
		I L GetSum(int p,int lf,int rt,int d){
			if(lf==rt){
				return sum[p];
			}
			if(d>tot[p<<1|1]){
				return sum[p<<1|1]+GetSum(p<<1,lf,lf+rt>>1,d-tot[p<<1|1]);
			}
			return GetSum(p<<1|1,lf+rt+2>>1,rt,d); 
		}
}T;
int dist[200000],ct;
I int GetDist(int x){
	return upper_bound(dist,dist+ct,x)-dist;
} 
int main(){
	int n;
	scanf("%d",&n);
	for(R i=0;i!=n;i++){
		scanf("%d%d",&s[i].type,&s[i].d);
		if(s[i].d>0){
			dist[i]=s[i].d;
		}
	}
	sort(dist,dist+n);
	ct=unique(dist,dist+n)-dist;
	int lit=0;
	L totsum=0;
	multiset<int>Q;
	for(R i=0;i!=n;i++){
		int tem=s[i].d;
		totsum+=tem;
		if(s[i].d>0){
			lit+=s[i].type;
			s[i].d=GetDist(s[i].d);
			if(s[i].type==1){
				Q.insert(s[i].d);
			}
		}else{
			lit-=s[i].type;
			s[i].d=-GetDist(-s[i].d);
			if(s[i].type==1){
				Q.erase(Q.find(-s[i].d));
			}
		}
		if(s[i].d>0){
			T.Modify(1,1,ct,s[i].d,1,tem);
		}else{
			T.Modify(1,1,ct,-s[i].d,-1,tem);
		}
		if(lit==0){
			printf("%lld\n",totsum);
		}else{
			int minl=*Q.begin();
			T.Modify(1,1,ct,minl,-1,-dist[minl-1]);
			printf("%lld\n",totsum+T.GetSum(1,1,ct,lit!=n?lit:n-1));
			T.Modify(1,1,ct,minl,1,dist[minl-1]);
		}
	}
	return 0;
}
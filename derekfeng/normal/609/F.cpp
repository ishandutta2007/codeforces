#include<bits/stdc++.h>
using namespace std;
struct frog{
	long long x,l,i,eat;
	bool operator< (const frog& other) const{
		return x<other.x;
	}
}A[200000];
int N,M;
long long bit[200001];
long long ans[200001][2];
void add(int x,long long v){
	for(x++;x<=N;x+=x&-x)
		bit[x]=max(bit[x],v);
}
long long ask(int x){
	long long ret=-1;
	for(x++;x>0;x-=x&-x)
		ret=max(ret,bit[x]);
	return ret;
}
int main(){
	memset(bit,-1,sizeof bit);
	scanf("%d%d",&N,&M);
	int a,b;
	for(int i=0;i<N;i++){
		scanf("%d%d",&a,&b);
		A[i].x=a;
		A[i].l=b;
		A[i].i=i;
		A[i].eat=0;
	}
	sort(A,A+N);
	for(int i=0;i<N;i++)
		add(i,A[i].x+A[i].l);
	multiset<pair<int,int> >uneaten;
	for(int i=0;i<M;i++){
		scanf("%d%d",&a,&b);
		int lo=-1,mid,hi=N-1;
		while(lo<hi){
			mid=(lo+hi+1)/2;
			if(A[mid].x<=a)lo=mid;
			else hi=mid-1;
		}
		if(hi==-1){
			uneaten.insert({a,b});
		}else{
			lo=0;
			while(lo<hi){
				mid=(lo+hi)/2;
				if(ask(mid)<a)lo=mid+1;
				else hi=mid; 
			}
			if(ask(lo)<a){
				uneaten.insert({a,b});
			}else{
				A[lo].eat++;
				A[lo].l+=b;
				auto it=uneaten.lower_bound({A[lo].x,-1});
				while(it!=uneaten.end()&&A[lo].x+A[lo].l>=it->first){
					auto nit=it;++nit;
					A[lo].eat++;
					A[lo].l+=it->second;
					uneaten.erase(it);
					it=nit;
				}
				add(lo,A[lo].x+A[lo].l);
			}
		}
	}
	for(int i=0;i<N;i++)ans[A[i].i][0]=A[i].eat,ans[A[i].i][1]=A[i].l;
	for(int i=0;i<N;i++)printf("%lld %lld\n",ans[i][0],ans[i][1]);
	return 0;
}
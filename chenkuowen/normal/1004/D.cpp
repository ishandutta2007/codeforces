#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<vector>
using namespace std;
const int MAX_N=5+1e6;
class Segment_tree{
	private:
		struct Node{
			int key; int tag;
		}tree[MAX_N<<2];
		inline void put_tag(int p,int tag){
			tree[p].key+=tag;
			tree[p].tag+=tag;
		}
		inline void down(int p){
			put_tag(p+p,tree[p].tag);
			put_tag(p+p+1,tree[p].tag);
			tree[p].tag=0;
		}
		inline void up(int p){
			tree[p].key=min(tree[p+p].key,tree[p+p+1].key);
		}
	public:
		void build(int* a,int p,int l,int r){
			tree[p].tag=0;
			if(l==r){
				tree[p].key=a[l];
				return;
			}
			int mid=(l+r)>>1;
			build(a,p+p,l,mid);
			build(a,p+p+1,mid+1,r);
		}
		void change(int p,int l,int r,int x,int y,int key){
			if(l==x&&r==y){ 
				put_tag(p,key);
				return;
			}
			down(p);
			int mid=(l+r)>>1;
			if(y<=mid) change(p+p,l,mid,x,y,key);
			else if(x>mid) change(p+p+1,mid+1,r,x,y,key);
			else change(p+p,l,mid,x,mid,key),change(p+p+1,mid+1,r,mid+1,y,key);
			up(p);
		}
		int mininum(){
			return tree[1].key;
		}
};
Segment_tree seg;
int cnt[MAX_N],max_key=0,x,y,t;
vector<pair<int,int> > q;
bool judge(int n,int m){
	q.clear(),y=n+m-x-max_key;
	if(y<1||y>m) return false;
	//printf("{%d %d}",x,y);
	for(int i=1;i<=m;++i){
		int key=abs(i-y);
		seg.change(1,0,t,key,key+x-1,-1);
		q.push_back(make_pair(key,key+x-1));
		//printf("[%d %d]",key,key+x-1);
		if(x<n){
			seg.change(1,0,t,key+1,key+n-x,-1);
			q.push_back(make_pair(key+1,key+n-x));
			//printf("[%d %d]",key+1,key+n-x);
		}
	}
	int key=seg.mininum();
	//printf("[%d]",key);
	for(int i=0;i<(int)q.size();++i) seg.change(1,0,t,q[i].first,q[i].second,1);
	return (key==0);
}
int main(){
	scanf("%d",&t);
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=t;++i){
		int key; scanf("%d",&key);
		if(key>max_key) max_key=key;
		++cnt[key];
	}
	seg.build(cnt,1,0,t);
	//for(int i=1;i<=t;++i) printf("%d ",cnt[i]);
	for(x=1;cnt[x]==(x<<2);++x);
	//printf("(%d)",x);
	for(int i=1;i<=t;++i)
		if(t%i==0)
			if(judge(i,t/i)){
				printf("%d %d\n%d %d\n",i,t/i,x,y);
				return 0;
			}
	//printf("[%d]",judge(4,5));
	printf("-1");
	return 0;
}
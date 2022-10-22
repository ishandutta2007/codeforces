#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+4e5,INF=2e9;
vector<int> key;
pair<int,int> tree[MAX_N<<2];
struct SEG{
	inline void up(int x){
		tree[x]=max(tree[x+x],tree[x+x+1]);
	}
	void build(int p,int l,int r){
		if(l==r){
			tree[p]=make_pair(0,0);
			return;
		}
		int mid=l+r>>1;
		build(p+p,l,mid);
		build(p+p+1,mid+1,r);
		up(p);
	}
	void change(int p,int l,int r,int x,pair<int,int> key){
		if(l==r){
			tree[p].first+=key.first;
			tree[p].second+=key.second;
			return;
		}
		int mid=l+r>>1;
		if(x<=mid) change(p+p,l,mid,x,key);
		else change(p+p+1,mid+1,r,x,key);
		up(p);
	}
	pair<int,int> query(int p,int l,int r,int x,int y){
		if(l==x&&r==y) return tree[p];
		int mid=l+r>>1;
		if(y<=mid) return query(p+p,l,mid,x,y);
		else if(x>mid) return query(p+p+1,mid+1,r,x,y);
		else return max(query(p+p,l,mid,x,mid)
			,query(p+p+1,mid+1,r,mid+1,y));
	}
	int search(int p,int l,int r,int x,int y,int key){
		if(tree[p].first<key) return -1;
		if(l==r) return tree[p].second;
		int mid=l+r>>1;
		if(y<=mid) return search(p+p,l,mid,x,y,key);
		else if(x>mid) return search(p+p+1,mid+1,r,x,y,key);
		else{
			int k=search(p+p,l,mid,x,mid,key);
			if(k!=-1) return k;
			return search(p+p+1,mid+1,r,mid+1,y,key);
		}
	}
}seg1;
int poi[MAX_N],cnt[MAX_N];
pair<int,int> a[MAX_N],b[MAX_N];
multiset<pair<int,int> > g;
void updata_frog(int x){
	multiset<pair<int,int> >::iterator
		 it=g.lower_bound(make_pair(key[a[x].second-1],0));
	while(it!=g.end()&&it->first<=a[x].first){
		a[x].first+=it->second;
		++cnt[x];
		seg1.change(1,1,key.size(),a[x].second,make_pair(it->second,0));
		multiset<pair<int,int> >::iterator
			 it1=it; ++it1;
		g.erase(it); it=it1;
	}
}
void add_mos(int x){
	int rpos=lower_bound(key.begin(),key.end(),b[x].second)-key.begin()+1;
//	printf("|%d|",rpos);
	int f=seg1.search(1,1,key.size(),1,rpos,b[x].second);
//	printf("{%d}\n",f);
	if(f==-1) return;
	updata_frog(f);
}
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&a[i].second,&a[i].first); 
		a[i].first+=a[i].second;
		key.push_back(a[i].second);
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d",&b[i].second,&b[i].first);
		key.push_back(b[i].second);
	}
	sort(key.begin(),key.end());
	key.erase(unique(key.begin(),key.end()),key.end());
	seg1.build(1,1,key.size());
//	for(int i=0;i<key.size();++i) printf("<%d>",key[i]);
	for(int i=1;i<=n;++i){
//		printf("{%d}",a[i].second);
		a[i].second=lower_bound(key.begin(),key.end(),a[i].second)
			-key.begin()+1;
		poi[a[i].second]=i;
//		printf("[%d]",a[i].first);
		seg1.change(1,1,key.size(),a[i].second,make_pair(a[i].first,i));
	}
//	for(int i=1;i<=key.size();++i) printf("|%d|",poi[i]);
	for(int i=1;i<=m;++i){
		g.insert(make_pair(b[i].second,b[i].first));
//		cerr<<"A"<<endl;
		add_mos(i);
	}
	for(int i=1;i<=n;++i) 
		printf("%d %d\n",cnt[i],a[i].first-key[a[i].second-1]);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int MAX_N=5+2e5;
struct SEG{
	int t[MAX_N<<2];
	inline void up(int x){
		t[x]=max(t[x+x],t[x+x+1]);
	}
	void build(int p,int l,int r){
		t[p]=0;
		if(l==r) return;
		int m=l+r>>1;
		build(p+p,l,m);
		build(p+p+1,m+1,r);
	}
	void change(int p,int l,int r,int x,int key){
		if(l==r){
			t[p]=key;
			return;
		}
		int m=l+r>>1; 
		if(x<=m) change(p+p,l,m,x,key);
		else change(p+p+1,m+1,r,x,key);
		up(p);
	}
	int query(int p,int l,int r,int x,int y){
		if(y<l||r<x) return 0;
		if(x<=l&&r<=y) return t[p];
		int m=l+r>>1; 
		return max(query(p+p,l,m,x,y),query(p+p+1,m+1,r,x,y));
	}
}seg1,seg2;
set<pair<int,int> > s;
int pos[15],top=(int)2e5+20;
void add(int p,int h,int key){
//	printf("[%d %d %d]",p,h,key);
	seg1.change(1,1,top,p,key);
	seg2.change(1,1,top,h,key);
}
void erase(int p,int h){
//	printf("{%d %d}",p,h);
	seg1.change(1,1,top,p,0);
	seg2.change(1,1,top,h,0);
}
void update_pos(int ti){
	for(int i=10;i>=1;--i) pos[i]=pos[i-1];
}

int main(){
	int n,m; scanf("%d%d",&n,&m);
	seg1.build(1,1,top);
	seg2.build(1,1,top);
	for(int ti=1;ti<=m;++ti){
		update_pos(ti);
		int opt; scanf("%d",&opt);
		if(opt==1){
			int p,h; scanf("%d%d",&p,&h);
			for(int i=1;i<=10;++i)
				if(pos[i]!=0)
					erase(pos[i],(int)2e5-ti+i);
			pos[h]=p;
			for(int i=10;i>=1;--i)
				if(pos[i]!=0)
					add(pos[i],(int)2e5-ti+i,seg1.query(1,1,top,pos[i],top)+1);
			s.insert(make_pair(p,(int)2e5-ti+h));
		}else{
			int x; scanf("%d",&x);
			vector<pair<int,int> > f;
			for(int i=1;i<=10;++i)
				if(!s.empty()){
					f.push_back(*s.begin());
					s.erase(s.begin());
				}
			for(int i=0;i<f.size();++i)
				erase(f[i].first,f[i].second);
			for(int i=1;i<=10;++i)
				if(pos[i]==f[x-1].first) pos[i]=0;
			f.erase(f.begin()+x-1);
			for(int i=(int)f.size()-1;i>=0;--i){
				s.insert(f[i]);
				int p=f[i].first,h=f[i].second;
				add(p,h,seg2.query(1,1,top,h,top)+1);
			}
		}
		printf("%d\n",seg1.query(1,1,top,1,top));
	}
	return 0;
}
#include<bits/stdc++.h>
const int Q=2e5+3,K=19,D=1<<18;
struct point{
	int x,y;
	point(int _x=0,int _y=0){x=_x,y=_y;}
	bool operator<(const point&b)const{return x==b.x?y<b.y:x<b.x;}
};
std::map<point,int>t;
int n,m,q;
struct segment_tree0{
	int mx[1<<K];
	void Init(){std::fill(mx,mx+(1<<K),-1);}
	void Update(int k,int a,int f){
		for(k+=D,mx[k]=std::max(f?-1:mx[k],a),k>>=1;k;k>>=1)mx[k]=std::max(mx[k<<1],mx[k<<1|1]);
	}
	int Max(int l,int r){
		int res=-1;
		for(l+=D-1,r+=D+1;l^r^1;l>>=1,r>>=1){
			if(~l&1)res=std::max(res,mx[l^1]);
			if( r&1)res=std::max(res,mx[r^1]);
		}
		return res;
	}
}t0;
struct segment_tree1{
	int mn[1<<K];
	void Init(){std::fill(mn,mn+(1<<K), m);}
	void Update(int k,int a,int f){
		for(k+=D,mn[k]=std::min(f? m:mn[k],a),k>>=1;k;k>>=1)mn[k]=std::min(mn[k<<1],mn[k<<1|1]);
	}
	int Min(int l,int r){
		int res= m;
		for(l+=D-1,r+=D+1;l^r^1;l>>=1,r>>=1){
			if(~l&1)res=std::min(res,mn[l^1]);
			if( r&1)res=std::min(res,mn[r^1]);
		}
		return res;
	}
}t1;
bool fl[1<<K];
std::vector<point>upt[1<<K];
#define M (L+R>>1)
void Insert(int l,int r,point p,int L,int R,int k){
	if(l<=L&&R<=r){upt[k].push_back(p);return;}
	if(l<=M)Insert(l,r,p,L  ,M,k<<1  );
	if(r> M)Insert(l,r,p,M+1,R,k<<1|1);
}
void Dfs(int L,int R,int k){
	point p;
	for(int i=0;i<upt[k].size();i++){
		p=upt[k][i];
		if(p.x&1){
			upt[k][i].y=t1.Min(p.x>>1,p.x>>1),t1.Update(p.x>>1,p.y,0);
			fl[k]|=t0.Max(p.x>>1,n-1)>=p.y;
		}
		else{
			upt[k][i].y=t0.Max(p.x>>1,p.x>>1),t0.Update(p.x>>1,p.y,0);
			fl[k]|=t1.Min(  0,p.x>>1)<=p.y;
		}
	}
	if(L==R){
		puts(fl[k]?"NO":"YES");
		for(int i=(int)upt[k].size()-1;~i;i--){
			p=upt[k][i];
			if(p.x&1)
				t1.Update(p.x>>1,p.y,1);
			else
				t0.Update(p.x>>1,p.y,1);
		}
		return;
	}
	fl[k<<1  ]|=fl[k],Dfs(L,M  ,k<<1  );
	fl[k<<1|1]|=fl[k],Dfs(M+1,R,k<<1|1);
	for(int i=(int)upt[k].size()-1;~i;i--){
		p=upt[k][i];
		if(p.x&1)
			t1.Update(p.x>>1,p.y,1);
		else
			t0.Update(p.x>>1,p.y,1);
	}
}
int main(){
	point p;
	scanf("%d%d%d",&n,&m,&q);
	for(int j=1;j<=q;j++){
		scanf("%d%d",&p.x,&p.y),p.x=p.x-1^1,p.y=p.y-1>>1;
		if(t.count(p))Insert(t[p],j-1,p,1,q,1),t.erase(p);
		else t[p]=j;
	}
	for(auto it=t.begin();it!=t.end();it++)Insert(it->second,q,it->first,1,q,1);
	t0.Init(),t1.Init();
	Dfs(1,q,1);
	return 0;
}
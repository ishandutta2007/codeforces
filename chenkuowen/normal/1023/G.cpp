#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
struct K{ 
	int time,x,type,id; //type=1 means should borrow x point, type=-1 means there are extra x point
	int query(int d){ return time-d*type; }
};
inline bool operator==(K x,K y){
	return x.time==y.time&&x.type==y.type&&x.id==y.id; 
}
inline bool operator!=(K x,K y){
	return !(x==y);
}
bool check_lex(K x,K y){
	if(x.id!=y.id) return x.id<y.id;
	return x.type<y.type; 
}
struct K2{
	int k; K p1,p2;
	K2(K g1,K g2){ p1=g1,p2=g2; k=g2.time-g1.time; } 
};
bool check_k2(K x,K y){ return x.type==-1&&y.type==1; }
bool operator<(K2 x,K2 y){ 
	if(x.k!=y.k) return x.k<y.k;
	if(x.p1!=y.p1) return check_lex(x.p1,y.p1);
	return check_lex(x.p2,y.p2);
}
bool operator>(K2 x,K2 y){ return y<x; }
int overall_delta;
struct Cmp{
	inline bool operator()(K x,K y){
		int kx=x.query(overall_delta),ky=y.query(overall_delta);
		if(kx!=ky) return kx<ky;
		if(x.type!=y.type){
			if(x.id==y.id) return x.type>y.type;
			else return x.type<y.type;
		}
		if(x.type==-1) return x.id>y.id;
		else return x.id<y.id;	
	}
};
struct Delta{
	int delta;
	Delta(){ delta=0; }
	K2 to_inside_form(K2 x){ 
		return K2(to_inside_form(x.p1),to_inside_form(x.p2)); 	
	}
	K2 to_outside_form(K2 x){
		return K2(to_outside_form(x.p1),to_outside_form(x.p2));
	}
	K to_inside_form(K x){ x.time+=delta*x.type; return x; }
	K to_outside_form(K x){ x.time-=delta*x.type; return x; }
	void add_delta(int x){ delta+=x; }
};
struct SS:Delta{
	multiset<K,Cmp> s;
	size_t size(){ return s.size(); }
	bool empty(){ return s.empty(); }
	void clear(){ delta=0; s.clear(); }
	void insert(K x){
		x=to_inside_form(x);
		overall_delta=delta;
		s.insert(x);
	}
	void erase(K x){
		x=to_inside_form(x);
		overall_delta=delta;
		auto it=s.find(x);
		assert(it!=s.end());
		s.erase(it);
	}
	void get_pos(K x,K& y,bool& f1,K& z,bool& f2){
		overall_delta=delta;
		x=to_inside_form(x);
		auto it=s.find(x);
		assert(it!=s.end());
		if(it==s.begin()) f1=false;
		else{
			y=to_outside_form(*prev(it));
			f1=true;
		}
		if(it==prev(s.end())) f2=false;
		else{
			z=to_outside_form(*next(it));
			f2=true;
		}
	}
	void traverse(vector<K>& ret){
		overall_delta=delta;
		for(auto x:s)
			ret.push_back(to_outside_form(x));
	}
};
struct QQ:Delta{
	multiset<K2> s;
	void push(K2 x){
		overall_delta=delta;
		x=to_inside_form(x);
		s.insert(x);
	}
	K2 top(){
		overall_delta=delta;
		return to_outside_form(*s.begin());
	}
	void erase(K2 x){
		overall_delta=delta;
		x=to_inside_form(x);
		auto it=s.find(x);
		assert(it!=s.end());
		s.erase(it);	
	}
	void pop(){erase(top()); }
	bool empty(){ return s.empty(); }
	size_t size(){ return s.size(); }
	void clear(){ delta=0; s.clear(); }
};
struct OP{
	SS s;
	QQ q;
	void insert(K x){
		K y,z;
		bool f1,f2;
		s.insert(x);
		s.get_pos(x,y,f1,z,f2);
		if(f1&&f2&&check_k2(y,z)){
			q.erase(K2(y,z));
		}
		if(f1&&check_k2(y,x)) q.push(K2(y,x));
		if(f2&&check_k2(x,z)) q.push(K2(x,z));
	}
	void erase(K x){
		K y,z;
		bool f1,f2;
		s.get_pos(x,y,f1,z,f2);
		if(f1&&f2&&check_k2(y,z)){
			q.push(K2(y,z));
		}
		if(f1&&check_k2(y,x)) q.erase(K2(y,x));
		if(f2&&check_k2(x,z)) q.erase(K2(x,z));
		s.erase(x);
	}
	void update(int t){
		while(!q.empty()&&q.top().k<t){
			K2 k=q.top(); 
			erase(k.p1);
			erase(k.p2);
			if(k.p1.x==k.p2.x);
			else if(k.p1.x<k.p2.x){
				k.p2.x-=k.p1.x;
				insert(k.p2);
			}else{
				k.p1.x-=k.p2.x;
				insert(k.p1);
			}
		}
	}
	void add_delta(int t){
		update(t+t);
		s.add_delta(t);
		q.add_delta(t);
	}
	void traverse(vector<K>& f){
		s.traverse(f);
	}
	int get_ans(){
		int ans=0,sum=0;
		vector<K> f; s.traverse(f);
		for(int i=0;i<f.size();++i){
			sum+=f[i].type*f[i].x;
			ans=max(ans,sum);
		}
		return ans;
	}
	size_t size(){ return s.size(); }
	void clear(){ q.clear(); s.clear(); }
}op[N];
vector<K> ff[N],last[N];
void merge(OP& x,OP& y){
	if(x.size()<y.size()) swap(x,y);
	vector<K> f; y.traverse(f); y.clear();
	for(auto t:f) x.insert(t);
}
struct Graph{
	struct Edge{ int to,nxt,key; }edge[N*2];
	int head[N],top;
	Graph(){memset(head,-1,sizeof(head)),top=-1;}
	inline void add(int x,int y,int k){
		edge[++top]=(Edge){y,head[x],k};
		head[x]=top;
	}
	inline void add2(int x,int y,int k){ add(x,y,k); add(y,x,k); }
}G;
int ti=0;
void dfs(int x,int pre,int len){
	for(int i=0;i<ff[x].size();i+=2){
		ff[x][i].id=ff[x][i+1].id=++ti;
		op[x].insert(ff[x][i]);
		op[x].insert(ff[x][i+1]);
	}
	for(int j=G.head[x];~j;j=G.edge[j].nxt){
		int y=G.edge[j].to;
		if(y!=pre){
			dfs(y,x,G.edge[j].key);
			op[y].add_delta(G.edge[j].key);
			merge(op[x],op[y]);
		}
	}
	op[x].update(len+len+(x==1));
}
int main(){
	int n; scanf("%d",&n);
	for(int i=1;i<n;++i){
		int x,y,w; scanf("%d%d%d",&x,&y,&w);
		G.add2(x,y,w);
	}
	int m; scanf("%d",&m);
	for(int i=0;i<m;++i){
		int t,x,pos; scanf("%d%d%d",&t,&x,&pos);
		ff[pos].push_back((K){t,x,-1,i});
		ff[pos].push_back((K){t,x,1,i});
	}
	dfs(1,0,0);
	printf("%d\n",op[1].get_ans());
	return 0;
}
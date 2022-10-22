#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX_N=5+1e6;
struct SBT{
    struct Node{ int s[2],fa,key,sz; };
    vector<Node> t;
    SBT(){ t.clear(); t.push_back((Node){{0,0},0,0,0}); rt=0; }
    inline int new_node(int fa,int key){
        t.push_back((Node){{0,0},fa,key,1});
        int ret=t.size()-1;
		return ret;
    }
    int rt;
    inline void up(int x){ t[x].sz=1+t[t[x].s[0]].sz+t[t[x].s[1]].sz; }
    inline void rotate(int x){
        int y=t[x].fa,z=t[y].fa,k=t[y].s[1]==x;
        if(rt==y) rt=x;
        else t[z].s[t[z].s[1]==y]=x;
        t[x].fa=z; t[y].fa=x; t[t[x].s[!k]].fa=y;
        t[y].s[k]=t[x].s[!k]; t[x].s[!k]=y; 
        up(y); up(x);
    }
    inline void fixup(int x){
        for(;x;x=t[x].fa){
            up(x);
            bool k=t[t[x].s[1]].sz>t[t[x].s[0]].sz;
            int y=t[x].s[k],z=t[x].s[!k],w=t[y].s[!k];
            if(t[z].sz<t[t[y].s[k]].sz) rotate(y),x=y;
            else if(t[z].sz<t[w].sz) rotate(w),rotate(w),x=w;
        }
    }
    inline void insert(int key){
        if(rt==0) return void(rt=new_node(0,key));
        int x=rt;
        while(t[x].s[key>t[x].key])
            x=t[x].s[key>t[x].key];
//		if(key==3) puts("A");
		int p=new_node(x,key);
        fixup(t[x].s[key>t[x].key]=p);
    }
    inline void erase(int key){
        int x=rt;
        while(key!=t[x].key)
            x=t[x].s[key>t[x].key];
        if(t[x].s[0]&&t[x].s[1]){
            int y=t[x].s[1];
            while(t[y].s[0]) y=t[y].s[0];
            swap(t[x].key,t[y].key); x=y;
        }
        int w=t[x].s[0]+t[x].s[1],y=t[x].fa;
        if(y==0) rt=w;
        else t[y].s[t[y].s[1]==x]=w;
        if(w) t[w].fa=y;
        fixup(y);
    }
    inline int k_th(int k){
        int x=rt,szx;
        while((szx=t[t[x].s[0]].sz+1)!=k){
            x=t[x].s[k>szx];
            if(k>szx) k-=szx;
        }
//		printf("(%d %d)",k,t[x].key);
        return t[x].key;
    }
    inline int gsz(int key){
        int x=rt,ret=0;
        while(x){
            if(key>t[x].key) ret+=t[t[x].s[0]].sz+1;
            x=t[x].s[key>t[x].key];
        }
        return ret;
    }
	inline int size(){ return t[rt].sz; }
    inline int pre(int x){ return k_th(gsz(x)); }
    inline int nxt(int x){ return k_th(gsz(x+1)+1); }
}sbt;
int a[MAX_N];
vector<int> g[MAX_N];
pair<ll,int> que[MAX_N];
int ans[MAX_N];
inline ll getint(){
	ll ret=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar());
	for(;c>='0'&&c<='9';c=getchar())
		ret=ret*10+c-'0';
	return ret;
}
int main(){
	int n=getint(),m=getint(),q=getint();
	for(int i=1;i<=n;++i) a[getint()]++;
	for(int i=1;i<=m;++i) g[a[i]].push_back(i);
	for(int i=1;i<=q;++i) {
		que[i].first=getint()-n;
		que[i].second=i;
	}
	sort(que+1,que+q+1);
	int poi=1; ll cnt=0;
	for(int i=0;i<=n;++i){
		for(auto j:g[i]) sbt.insert(j);
		ll cnt1=cnt+sbt.size();
		for(;poi<=q&&que[poi].first<=cnt1;++poi)
			ans[que[poi].second]=sbt.k_th(que[poi].first-cnt);
		cnt=cnt1;
	}
	for(;poi<=q;++poi)
		ans[que[poi].second]=sbt.k_th((que[poi].first-cnt-1)%m+1);
	for(int i=1;i<=q;++i) printf("%d\n",ans[i]);
	return 0;
}
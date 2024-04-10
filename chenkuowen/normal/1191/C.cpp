#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
namespace TREE{
    const int N=5+1e6;
    struct Node{ int s[2],key,sz; }t[N];
    int stk[N],top_stk=0,top=0;
    struct F{F(){t[0]=(Node){{0,0},0,0};}}f;
    struct SBT{
        inline int new_node(int key){
            int x=top_stk?stk[top_stk--]:++top;
            t[x]=(Node){{0,0},key,1};
            return x;
        }
        inline void up(int x){
            t[x].sz=t[t[x].s[0]].sz+t[t[x].s[1]].sz+1;
        }
        int rt;
        SBT(){ rt=0; }
        inline void rotate(int& x,int k){
            int y=t[x].s[k];
            t[x].s[k]=t[y].s[!k];
            t[y].s[!k]=x;
            up(x);  x=y;
        }
        inline void fixup(int& x){
            bool k=t[t[x].s[0]].sz<t[t[x].s[1]].sz;
            int &y=t[x].s[k],z=t[x].s[!k];
            if(t[z].sz<t[t[y].s[k]].sz) rotate(x,k);
            else if(t[z].sz<t[t[y].s[!k]].sz) rotate(y,!k),rotate(x,k);
            up(x);
        }
        inline void insert(int key,int& x){
            if(x==0) return void(x=new_node(key));
            insert(key,t[x].s[key>t[x].key]);
            fixup(x);
        }
        inline void insert(int key){ insert(key,rt); }
        inline void erase(int key,int& x){
            if(t[x].key==key){
                if(t[x].s[0]==0||t[x].s[1]==0){
                    x=t[x].s[0]+t[x].s[1];
                    return;
                }
                int y=t[x].s[1];
                while(t[y].s[0]) y=t[y].s[0];
                swap(t[y].key,t[x].key);
                erase(t[y].key,t[x].s[1]);
            }else
                erase(key,t[x].s[key>t[x].key]);
            fixup(x);
        }
        inline void erase(int key){ erase(key,rt); }
        inline int gsz(int key){
            int ret=0,x=rt;
            while(x){
                if(t[x].key<key) ret+=t[t[x].s[0]].sz+1;
                x=t[x].s[key>t[x].key];
            }
            return ret;
        }
        inline int k_th(int k){
            int x=rt,sz;
            while((sz=t[t[x].s[0]].sz+1)!=k){
                x=t[x].s[k>sz];
                if(k>sz) k-=sz;
            }
            return t[x].key;
        }
        inline int pre(int x){ return k_th(gsz(x)); }
        inline int nxt(int x){ return k_th(gsz(x+1)+1); }
        void dfs(int x){
            if(x==0) return;
            dfs(t[x].s[0]);
            printf("|%d %d %d %d %d|",x,t[x].s[0],t[x].s[1],t[x].key,t[x].sz);
            dfs(t[x].s[1]);
        }
    };
}
using TREE::SBT;
vector<ll> a;
int main(){
    ll n,m,k; scanf("%lld%lld%lld",&n,&m,&k);
	ll cnt=0,ans=0;
	for(int i=1;i<=m;++i){
		ll x; scanf("%lld",&x);
		a.push_back(x);
	}
	while(1){
		ll pos=a[cnt]; int i=cnt+1;
		for(;i<a.size()&&(a[i]-cnt-1)/k==(pos-cnt-1)/k;++i);
		++ans; cnt=i;
		if(i>=a.size()) break;
	}
	printf("%lld\n",ans);
	return 0;
}
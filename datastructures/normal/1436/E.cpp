#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#define maxn 200001
using namespace std;
int n,m,a[200005],nxt[200005],book[200005],ans[200005],s;
vector <int>pos[200005];
vector <int>c[200005],id[200005];
struct SGT{
    int tree[800005];
    SGT(){
        memset(tree,0,sizeof(tree));
        return;
    }
    inline void pushup(int now){
        tree[now]=max(tree[now*2],tree[now*2+1]);
        return;
    }
    inline void tree_upd(int now,int nowl,int nowr,int pos,int val){
        if (nowl==nowr){
            tree[now]=val;
            return;
        }
        int mid=(nowl+nowr)/2;
        if (pos<=mid)tree_upd(now*2,nowl,mid,pos,val);
        else tree_upd(now*2+1,mid+1,nowr,pos,val);
        pushup(now);
        return;
    }
    inline int tree_ask(int now,int nowl,int nowr,int val){
        if (nowl==nowr)return nowl;
        int mid=(nowl+nowr)/2;
        if (tree[now*2]>val)return tree_ask(now*2,nowl,mid,val);
        return tree_ask(now*2+1,mid+1,nowr,val);
    }
    inline void update(int pos,int val){
        tree_upd(1,1,maxn,pos,val);
    }
    inline int ask(int val){
        return tree_ask(1,1,maxn,val);
    }
}sgt;
inline void make_query(int x,int y){
	int i=++m;
	c[x].push_back(y),id[x].push_back(i);
	return;
}
int main(){
    cin>>n;
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(book,0x7f,sizeof(book));
    for (int i=n;i>=1;i--){
        nxt[i]=book[a[i]];
        book[a[i]]=i;
    }
    for (int i=1;i<=n+1;i++)
        sgt.update(i,book[i]);
    for (int i=1;i<=n+1;i++)
    	pos[i].push_back(0);
    for (int i=1;i<=n;i++)
    	pos[a[i]].push_back(i);
    for (int i=1;i<=n+1;i++)
    	pos[i].push_back(n+1);
    for (int i=1;i<=n+1;i++){
    	int size=pos[i].size();
    	for (int j=1;j<size;j++)
    		if (pos[i][j]-pos[i][j-1]>1)make_query(pos[i][j-1]+1,pos[i][j]-1);
	}
    for (int i=1;i<=n;i++){
        for (int j=0,len=c[i].size();j<len;j++)
            ans[id[i][j]]=sgt.ask(c[i][j]);
        if (a[i]!=0)sgt.update(a[i],nxt[i]);
    }
    m=0;
    s=n+2;
    for (int i=1;i<=n+1;i++){
    	int size=pos[i].size(),mx=0;
    	for (int j=1;j<size;j++)
    		if (pos[i][j]-pos[i][j-1]>1){
    			++m;
    			mx=max(mx,ans[m]);
			}
		if (mx!=i)s=min(s,i);
	}
    cout<<s<<endl;
    return 0;
}
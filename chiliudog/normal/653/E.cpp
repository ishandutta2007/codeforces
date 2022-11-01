#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long int64;
#define mk(a,b) make_pair(a,b)
#define w1 first
#define w2 second
typedef pair<int,int> pin;
const int maxn=300005;
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
}
set<int> res;
int tot,n,m,k;
map<pin,int> fb;
inline int dfs(int x){
	set<int>::iterator It;
	It=res.begin();int sz=1;
	while(It!=res.end()){
		bool flag=1;int w=*It;
		if(!fb.count(mk(x,*It))){
			res.erase(It),sz+=dfs(w);
			if(x==1)tot++;
			flag=0;
		}
		It=res.upper_bound(w);
	}return sz;
}
int main(){
    read(n);read(m);read(k);
    int cnt=n-1;
    rep(i,1,m){
    	int x,y;read(x);read(y);
    	if(x>y)swap(x,y);
    	if(x==1||y==1)cnt--;
    	fb[mk(x,y)]=1;fb[mk(y,x)]=1;
    }
    rep(i,2,n)res.insert(i);
   	if(cnt<k){
   		puts("impossible");return 0;
   	}
   	int w=dfs(1);
   	if(res.size()){
   		puts("impossible");return 0;
   	}
   	if(tot>k){
   		puts("impossible");return 0;
   	}puts("possible");
    return 0;
}
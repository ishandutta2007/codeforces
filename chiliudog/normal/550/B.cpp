#include<bits/stdc++.h>
#define fortodo(i,a,b) for(int i=(a);i<=(b);i++)
#define fordownto(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int maxn=16;
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

int n,l,r,x,a[maxn],ans;
vector<int> select;
inline void check(){
	int len=select.size(),minnum=1<<28,maxnum=-(1<<28);
	fortodo(i,0,len-1){
		minnum=min(minnum,select[i]);maxnum=max(maxnum,select[i]);
	}
	if (maxnum-minnum>=x) ans++;
}
inline void dfs(int x,int tot){
	if (tot>r) return;
	if (x==n+1){
		if (tot<l) return;
		check();return;
	}
	select.push_back(a[x]);
	dfs(x+1,tot+a[x]);
	select.pop_back();
	dfs(x+1,tot);
}
int main(){
   // judge();
	read(n);read(l);read(r);read(x);
	fortodo(i,1,n) read(a[i]);
	dfs(1,0);
	cout<<ans;
    return 0;
}
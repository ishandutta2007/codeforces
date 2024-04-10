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
const int maxn=1005;
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
int a[maxn],n;
map<int,int> zball;
int now[maxn];
inline int calc(int x,int y){
//	int ans=0;
	int len=2;
	now[1]=a[x];now[2]=a[y];
	zball[a[x]]--;zball[a[y]]--;
	while(233){
		len++;
		now[len]=now[len-1]+now[len-2];
		if((!zball.count(now[len]))||(zball.count(now[len])&&zball[now[len]]==0)){
			rep(i,1,len-1)zball[now[i]]++;
			return len-1;
		}
		zball[now[len]]--;
		if(now[len]==0&&now[len-1]==0){
			int ans=len+zball[0];
			rep(i,1,len)zball[now[i]]++;
			return ans;
		}
	}
}
int main(){
    read(n);
    rep(i,1,n)read(a[i]),zball[a[i]]++;
//    rep(i,-2,2)if(zball.count(i))printf("%d %d\n",i,zball[i]);
    int ans=0;
    rep(i,1,n)rep(j,1,n)if(i!=j){
    	ans=max(ans,calc(i,j));	
//	    rep(i,-2,2)if(zball.count(i))printf("%d %d\n",i,zball[i]);
	}
    cout<<ans<<endl;
    return 0;
}
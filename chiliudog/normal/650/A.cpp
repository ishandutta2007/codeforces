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
const int maxn=200005;
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
struct info{
	int x,y;
};
inline bool cmpX(const info &a,const info &b){
	return a.x<b.x;
}
inline bool cmpY(const info &a,const info &b){
	return a.y<b.y;
}
int n;
info a[maxn];
map<pin,int> zball;
int64 ans;
int cntx[maxn],cnty[maxn];
typedef map<pin,int>::iterator It;
int main(){
    read(n);
    rep(i,1,n)read(a[i].x),read(a[i].y);
    sort(a+1,a+1+n,cmpX);
    int counter=0;
    rep(i,1,n){
    	int j=i;while(j<n&&a[j+1].x==a[j].x)j++;
    	counter++;rep(k,i,j)a[k].x=counter;
    	i=j;
    }
    sort(a+1,a+1+n,cmpY);
    counter=0;
    rep(i,1,n){
    	int j=i;while(j<n&&a[j+1].y==a[j].y)j++;
    	counter++;rep(k,i,j)a[k].y=counter;
    	i=j;
    }
    rep(i,1,n)cntx[a[i].x]++;
    rep(i,1,n)cnty[a[i].y]++;
    rep(i,1,n)if(cntx[i])
    	ans+=1ll*(cntx[i])*(cntx[i]-1)/2;
    rep(i,1,n)if(cnty[i])
    	ans+=1ll*(cnty[i])*(cnty[i]-1)/2;
    rep(i,1,n)zball[mk(a[i].x,a[i].y)]++;
    for(It it=zball.begin();it!=zball.end();it++){
    		ans-=1ll*it->w2*(it->w2-1)/2;
    }
    cout<<ans;
    return 0;
}
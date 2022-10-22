#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
int rnd[N],num[N];
ll size[N];
int ls[N],rs[N];
int rt,P;
int build(int x){
    int p=++P;
    ls[p]=rs[p]=0;
    num[p]=x;
    rnd[p]=rand();
    size[p]=1;
    return p;
}
void update(int p){
	size[p]=size[ls[p]]+size[rs[p]]+1;
}
int merge(int x,int y){
    if(!x||!y) return x+y;
    if(rnd[x]<rnd[y]){
        rs[x]=merge(rs[x],y);
        update(x);
        return x;
    }
    else{
        ls[y]=merge(x,ls[y]);
        update(y);
        return y;
    }
}
void split(int p,int k,int &x,int &y){
    if(!p){
    	x=y=0;
    	return;
	}
    if(k>=num[p]){
        x=p;split(rs[p],k,rs[p],y);
    }
    else{
        y=p;split(ls[p],k,x,ls[p]);
    }
    update(p);
    return;
}
struct loc{
	int x,y;
	bool operator <(const loc &b)const
	{
		return (y==b.y)?(x<b.x):(y>b.y);
	}
};loc a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
	sort(a+1,a+n+1);
	ll ans=0;
	for(i=1;i<=n;){
		for(j=i;a[j].y==a[i].y&&j<=n;j++);
		int p1=0,p2=0,p3=0,p4=0;
		for(int k=i;k<j;k++){
		    p1=p2=p3=p4=0;
			split(rt,a[k].x-1,p1,p2);
			split(p2,a[k].x,p2,p3);
			if(k!=j-1)
				split(p3,a[k+1].x-1,p3,p4);
			ans+=(size[p1]+1)*(size[p3]+1);
			if(!p2) p2=build(a[k].x);
			rt=merge(merge(p1,p2),merge(p3,p4));
		}
		i=j;
	}
	cout<<ans;
	return 0;
}
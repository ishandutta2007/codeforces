#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
struct song{
	ll t,b;
	bool operator <(const song &x)const
	{
		return b==x.b?t<x.t:b<x.b;
	}
};
song s[N];
struct fhq{
    int ls,rs,rnd,size;
	ll num;
    ll sum;
};
int rt,P;
fhq f[N];
int build(ll x){
    int p=++P;
    f[p].ls=f[p].rs=0;
    f[p].num=f[p].sum=x;
    f[p].size=1;
    f[p].rnd=rand();
    return p;
}
void update(int p){
    f[p].size=f[f[p].ls].size+f[f[p].rs].size+1;
    f[p].sum=f[f[p].ls].sum+f[f[p].rs].sum+f[p].num;
}
void split(int p,int k,int &x,int &y){
    if(!p){
        x=y=0;
        return;
    }
    int s=f[f[p].ls].size;
    if(s<k){
        x=p;
        split(f[x].rs,k-s-1,f[x].rs,y);
    }
    else{
        y=p;
        split(f[y].ls,k,x,f[y].ls);
    }
    update(p);
}
void _split(int p,ll k,int &x,int &y){
    if(!p){
        x=y=0;
        return;
    }
    if(k>f[p].num){
        x=p;
        _split(f[x].rs,k,f[x].rs,y);
    }
    else{
        y=p;
        _split(f[y].ls,k,x,f[y].ls);
    }
    update(p);
}
int merge(int x,int y){
    if(!x||!y) return x+y;
    if(f[x].rnd<f[y].rnd){
        f[x].rs=merge(f[x].rs,y);
        update(x);
        return x;
    }
    else{
        f[y].ls=merge(x,f[y].ls);
        update(y);
        return y;
    }
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++) cin>>s[i].t>>s[i].b;
	sort(s+1,s+n+1);
	ll suf=0;
	ll ans=0;
	for(i=n;i;i--){
		ans=max(ans,(suf+s[i].t)*s[i].b);
		int p=build(s[i].t);
		int x=0,y=0,z=0;
		_split(rt,s[i].t,x,y);
		rt=merge(merge(x,p),y);
		x=y=0;
		if(f[rt].size>=m){
			split(rt,1,x,y);
			rt=y;	
		}
		suf=f[rt].sum;
	}
	cout<<ans;
	return 0;
}
#include <bits/stdc++.h>
#define int long long
using namespace std;

int n,m,ss,tt,a[400010],b[400010],xx[400010],yy[400010],sx[400010],sy[400010];

inline int Sum(int l,int r)
{
	return sx[r]-sx[l-1];
}

inline int sum(int x,int y,bool flag)
{
    if(xx[x]<y){
    	int res1=0;
        if(flag){
            if(ss>x&&tt>y) res1=1;
            if(ss<=x&&tt<=y&&tt<=xx[ss]) res1=1;
        }
        return 1ll*yy[y]*y+Sum(yy[y]+1,x)+1ll*(n-x)*(m-y)-res1;
    }
    else{
    	int res2=0;
	    if(flag){
	        if(ss<=x&&tt<=y) res2=1;
	        if(ss>x&&tt>y&&tt>xx[ss]) res2=1;
	    }
	    return 1ll*x*y+(1ll*(yy[y]-x)*m-Sum(x+1,yy[y]))+1ll*(n-yy[y])*(m-y)-res2;
	}
}

inline bool check(int x)
{
    xx[0]=m;
    for(int i=1;i<=n;i++){ 
        for(xx[i]=xx[i-1];xx[i]&&a[i]+b[xx[i]]>x;xx[i]--);
    }
    for(int i=1;i<=n;i++) sx[i]=sx[i-1]+xx[i];
    yy[0]=n;
    for(int i=1;i<=m;i++){
        for(yy[i]=yy[i-1];yy[i]&&a[yy[i]]+b[i]>x;yy[i]--);
    }
    int _0=max(Sum(1,n),1ll*n*m-Sum(1,n));
	int _1=max(Sum(1,n)-(tt<=xx[ss]),1ll*n*m-Sum(1,n)-(tt>xx[ss]));
    int pos=1;
    for(int i=1;i<=n;i++){
        while(pos<m&&sum(i,pos,0)<=sum(i,pos+1,0)) pos++;
        _0=max(_0,sum(i,pos,0));
    }
    pos=1;
    for(int i=1;i<=n;i++){
        while(pos<m&&sum(i,pos,1)<=sum(i,pos+1,1)) pos++;
        _1=max(_1,sum(i,pos,1));
    }
    return _0!=_1+1;
}

signed main()
{
	ios::sync_with_stdio(false);cin.tie(0); 
	cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
	ss=a[1],tt=b[1];
    sort(a+1,a+n+1);
	sort(b+1,b+m+1);
    ss=lower_bound(a+1,a+n+1,ss)-a;
	tt=lower_bound(b+1,b+m+1,tt)-b;
    int l=a[1]+b[1],r=a[ss]+b[tt],ans=a[ss]+b[tt];
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
        	r=mid-1;
        	ans=mid;
		}
        else l=mid+1;
    }
    cout<<ans<<'\n';
    return 0;
}
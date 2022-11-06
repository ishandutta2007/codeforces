#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define LL long long
#define FOR(i,a,b) for (int i=a;i<=b;++i)
#define FORD(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef pair<int,int> pa;
void getint(int &v){
    char ch,fu=0;
    for(ch='*'; (ch<'0'||ch>'9')&&ch!='-'; ch=getchar());
    if(ch=='-') fu=1, ch=getchar();
    for(v=0; ch>='0'&&ch<='9'; ch=getchar()) v=v*10+ch-'0';
    if(fu) v=-v;
}
LL n,k,l,r,t,lx,ly,rx,ry,ans;
int main(){
	cin>>n>>l>>r>>k;
	if (r>=l) t=r-l+1;
	else t=r+n-l+1;
	ans=-1;
	for (LL y=0;y<=10000000;++y){
		if (y>n) break;
		if (k-y+n-t*2<0) continue;
		rx=(k-y+n-t*2)/(y+n);
		
		if (k-t<0) continue;
		
		rx=min(rx,(k-t)/(y+n));
		
		LL tt=max(0ll,k-t-t);
		if (tt%(y+n)==0) lx=tt/(y+n);
		else lx=tt/(y+n)+1;
		if (lx<=rx) ans=max(ans,y);
	}
	
	
	if (t*2>=k && t<=k) ans=max(ans,min(n,k+n-t*2));
	
	
	for (LL x=1;x*x<=10000000;++x){
		LL tt=k-x*n+n-t*2;
		if (tt<0) continue;
		ry=tt/(x+1);
		
		if (k-t<0) continue;
		ry=min(ry,(k-t)/x-n);
		
		if (ry<0) continue;
		tt=max(0ll,k-t*2-x*n);
		if (tt%x==0) ly=tt/x;
		else ly=tt/x+1;
		ry=min(ry,n);
		if (ly<=ry) ans=max(ans,ry);
	}
	
	
	
	++k;
	
	for (LL y=0;y<=10000000;++y){
		if (y>n) break;
		if (k-y+n-t*2<0) continue;
		rx=(k-y+n-t*2)/(y+n);
		
		if (k-(t+1)<0) continue;
		
		rx=min(rx,(k-(t+1))/(y+n));
		
		LL tt=max(0ll,k-t-t);
		if (tt%(y+n)==0) lx=tt/(y+n);
		else lx=tt/(y+n)+1;
		if (lx<=rx && y>0) ans=max(ans,y);
	}
	
	
	if (t*2>=k && t<=k && min(n,k+n-t*2)>0) ans=max(ans,min(n,k+n-t*2));
	
	
	for (LL x=1;x*x<=10000000;++x){
		LL tt=k-x*n+n-t*2;
		if (tt<0) continue;
		ry=tt/(x+1);
		
		if (k-(t+1)<0) continue;
		ry=min(ry,(k-(t+1))/x-n);
		
		if (ry<0) continue;
		tt=max(0ll,k-t*2-x*n);
		if (tt%x==0) ly=tt/x;
		else ly=tt/x+1;
		ry=min(ry,n);
		if (ly<=ry && ry>0) ans=max(ans,ry);
	}
	
	
	cout<<ans<<endl;
	return 0;
}
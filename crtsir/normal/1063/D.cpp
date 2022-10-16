#include<bits/stdc++.h>
using namespace std;
long long n,l,r,K,x,y;
int main(){
//	freopen("mk.in","r",stdin);
//	freopen("mk.out","w",stdout);
	cin>>n>>l>>r>>K;
	x=(r-l+1+n)%n;
	if(x==0)x=n;
	y=n-x;
	if(n<=10000000){
		int ans=-1;
		for(int i=0;i<=n;i++){
			long long l=K-x-min(1ll*i,x),r=K-x-max(0ll,i-y);
			if(r>=0&&(r/(n+i))*(n+i)>=l)
				ans=i;
			l++;
			r=K-x+1-max(1ll,i-y);
			if(r>=0&&(r/(n+i))*(n+i)>=l)
				ans=i;
		}
		cout<<ans;
	}else{
		long long ans=-1;
		if(x*2>=K&&x<=K)
			ans=K-x+y+1;
		for(int i=1;i<=10000;i++){
			if((K-x)%i>x)
				continue;
			long long lc=0,_=(K-x)%i,rc=(x-_)/i,mid,c,d;
			while(lc!=rc){
				mid=(lc+rc>>1);
				c=mid*i+_;
				if((K-x-c)/i-n-c<=y)
					rc=mid;
				else
					lc=mid+1;
			}c=lc*i+_;d=(K-x-c)/i-n-c;
			if(c>x||d>y||d<0)continue;
			ans=max(ans,c+d);
		}
		for(int i=1;i<=10000;i++){
			if((K-x)%i>x-1)
				continue;
			long long lc=0,_=(K-x)%i,rc=(x-1-_)/i,mid,c,d;
			while(lc!=rc){
				mid=(lc+rc>>1);
				c=mid*i+_;
				if((K-x-c)/i-n-c-1<=y)
					rc=mid;
				else
					lc=mid+1;
			}c=lc*i+_;d=(K-x-c)/i-n-c-1;
			if(c>x-1||d>y||d<0)continue;
			ans=max(ans,c+d+1);
		}
		cout<<ans;
	}
}
#include<iostream>
#include<cmath>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;i++)
#define rep0(i,n) for(int i=0;i<n;i++)
#define REP(i,x,y) for(int i=x;i<=y;i++)
int a[100009];
int ml[100009],mr[100009];
int main(){
	int n,k;
	cin>>n>>k;
	int minn=2e9,maxn=-2e9;
	rep(i,n){
		scanf("%d",&a[i]); 
		minn=min(a[i],minn);
		maxn=max(a[i],maxn);
	}
	if(k==1)cout<<minn<<endl;
	else if(k>=3) cout<<maxn<<endl;
	else{
		ml[0]=2e9;
		mr[n+1]=2e9;
		rep(i,n)ml[i]=min(ml[i-1],a[i]);
		for(int j=n;j>0;j--)mr[j]=min(mr[j+1],a[j]);
		int ans=-2e9;
		rep(i,n-1){
			ans=max(ans,max(ml[i],mr[i+1]));
		}
		cout<<ans<<endl;
	}
	return 0;
}
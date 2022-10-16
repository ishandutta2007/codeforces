#include<bits/stdc++.h>
using namespace std;
int n,m,a[200003],b[200003],A,B,x,y,minn[200003],ed[200003];
long long sum[200003];
long long calc(int i,int j){
	if(ed[j]>=i)
		return 1ll*j*i;
	else
		return 1ll*j*ed[j]+sum[i]-sum[ed[j]];
}
long long solve(int i,int j,int tp){
	long long ret=1ll*(n-i)*(m-j)-calc(n,m)+calc(n,j)+calc(i,m);
	if(x>=i&&y>=j&&tp)ret--;return ret;
}
bool check(int val){
	for(int i=n-1,j=0;i>=0;i--){
		while(j<m&&a[i]+b[j]<val)j++;
		minn[i]=j;
	}for(int i=0;i<=m;i++)ed[i]=n;
	for(int i=0,j=m;i<n;i++){
		while(j>minn[i])
			ed[j]=i,j--;
		sum[i+1]=sum[i]+minn[i];
	}
	long long maxn1=0,maxn2=0;
	for(int i=0,j=0;i<=n;i++){
		while(j+1<=m&&solve(i,j,0)<solve(i,j+1,0))j++;
		maxn1=max(maxn1,solve(i,j,0));
	}for(int i=0,j=0;i<=n;i++){
		while(j+1<=m&&solve(i,j,1)<solve(i,j+1,1))j++;
		maxn2=max(maxn2,solve(i,j,1));
	}return maxn1!=maxn2;
}
int main(){cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];A=a[0];
	for(int i=0;i<m;i++)
		cin>>b[i];B=b[0];
	sort(a,a+n);sort(b,b+m);
	for(int i=0;i<n;i++)
		if(A==a[i])x=i;
	for(int i=0;i<m;i++)
		if(B==b[i])y=i;
	int l=a[0]+b[0],r=A+B;
	while(l!=r){
		int mid=(l+r+1>>1);
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}cout<<l;
}
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
const ll mod=1e9+7;
const ll N=1e5+5;
 
using namespace std;
 
ll T;
ll n,m,k;
ll x,y,l,r,mid,res,ret,tmp;
ll p,q,pos,sum,ans;
ll a[50][50];
 
ll get(){
	char x;int f=1;
	while ((x=getchar())<'0'||x>'9')
		if (x=='-') f=-1;
	ll sum=x-'0';
	while ((x=getchar())>='0'&&x<='9')
		sum=sum*10+x-'0';
	return sum*f;
}
//initialize
void solve(){
	n=get();m=get();
	res=-1e9-1;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			a[i][j]=get();
			if (a[i][j]>res){
				res=a[i][j];
				x=i;y=j;
			}
		}
	}
	cout<<max(x,n-x+1)*max(y,m-y+1)<<"\n";
}
 
int main(){
	//std::ios::sync_with_stdio(false);
	//srand(time(NULL));
	T=1;
	T=get();
	while (T--) solve();
	return 0;
}
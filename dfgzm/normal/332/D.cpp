#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2010;
const long double eps=1e-4;
int i,j,k,n,m,a[maxn][maxn],num[maxn];
ll S[maxn];
long double get(int a,int b,int c,int d,long double w){
	for(int i=1;i<=b-a+1;i++){
		w*=(a+i-1);w/=(c+i-1);
	}
	return w;
}
long double ans;
int main(){
	cin>>n>>m;
//	for(i=1;i<=n;i++)num[i]=1;
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			scanf("%d",&a[i][j]);
			a[j][i]=a[i][j];
			if(a[i][j]!=-1){
				S[i]+=a[i][j];
				S[j]+=a[i][j];
				num[i]++;
				num[j]++;
			}
		}
	}
	for(i=1;i<=n;i++)if(num[i]>=m){
		ans+=get(num[i]-m+1,num[i]-1,n-m+1,n-1,(double)1.*m*S[i]/n);
	}
	cout<<(ll)(ans+eps)<<endl;
	return 0;
}
/*
C(num[i]-1,m-1)/C(n,m)
num[i]-1! n-m! m
num[i]-m! n!
*/
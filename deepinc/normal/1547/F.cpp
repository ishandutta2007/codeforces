#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
map<int,int>m;
vector<int>v[1111111];
int a[222222],c,ans;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
	int t;cin>>t;while(t--){
		int n,g;cin>>n;
		for(int i=1;i<=n;++i)cin>>a[i];
		g=a[1]; for(int i=2;i<=n;++i)g=gcd(a[i],g);
		for(int i=1;i<=n;++i){
			a[i]/=g;
			for(int j=2;j<=1000&&j*j<=a[i];++j)if(a[i]%j==0){
				int&o=m[j]; if(!o)o=++c;
				v[o].push_back(i);
				while(a[i]%j==0)a[i]/=j;
			}
			if(a[i]!=1){
				int&o=m[a[i]]; if(!o)o=++c;
				v[o].push_back(i);
			}
		}
		for(int i=1,t;t=v[i].size(),i<=c;++i){
			for(int j=0;j<t;++j)v[i].push_back(v[i][j]+n);
			for(int j=1,q=1;j<t<<1;++j)q=v[i][j]==v[i][j-1]+1?q+1:1,ans=max(ans,q);
			v[i].clear();
		}
		printf("%d\n",ans); m.clear();c=ans=0;
	}
}
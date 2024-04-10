#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[111],b[111],ans[222];
int main(){
	int t;cin>>t;while(t--){
		int k,n,m,A=1,B=1,c=0;
		cin>>k>>n>>m;
		for(int i=1;i<=n;++i)cin>>a[i];
		for(int i=1;i<=m;++i)cin>>b[i];
		while(A<=n||B<=m){
			int o=0;
			while(A<=n&&a[A]<=k)k+=!a[A],ans[++c]=a[A],A++,o=1;
			while(B<=m&&b[B]<=k)k+=!b[B],ans[++c]=b[B],B++,o=1;
			if(!o){puts("-1");goto F;}
		}for(int i=1;i<=c;++i)printf("%d ",ans[i]);puts("");F:;
	}
}
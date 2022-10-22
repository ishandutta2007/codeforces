#include<bits/stdc++.h>
using namespace std;
int T,n,m,a[90100],p[90100],g[310][310],res;
vector<int>v;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m),res=0;
		for(int i=0;i<n*m;i++)scanf("%d",&a[i]),p[i]=i;
		sort(p,p+n*m,[](int x,int y){return a[x]!=a[y]?a[x]<a[y]:x>y;});
		for(int l=0,r=0,k,j;l<n*m;l=r){
			while(r<n*m&&a[p[l]]==a[p[r]])v.push_back(p[r++]);
			sort(v.begin(),v.end());
			k=l,j=0;
			while(l!=r){
				while(k!=r&&k%m)k++;
				for(int i=k-1;i>=l;i--)p[i]=v[j++];
				l=k++;
			}
			v.clear();
		}
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int k=0;k<j;k++)if(p[i*m+k]<p[i*m+j])res++;
		printf("%d\n",res);
	}
	return 0;
}
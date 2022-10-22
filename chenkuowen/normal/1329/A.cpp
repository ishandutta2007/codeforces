#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
template<class T> inline void dmin(T& x,T y){ y<x?x=y:0; }
template<class T> inline void dmax(T& x,T y){ y>x?x=y:0; }
template<class T> inline void dmin(T& x,vector<T> y){ 
	for(auto t:y) t<x?x=t:0;
}
template<class T> inline void dmax(T& x,vector<T> y){
	for(auto t:y) t>x?x=t:0;
}
int main(){
	vector<int> l,p; 
	int n,m; scanf("%d%d",&n,&m);
	l.resize(m); p.resize(n);
	for(int i=0;i<m;++i){
		scanf("%d",&l[i]);
		if(i+l[i]-1>=n){
			puts("-1");
			exit(0);
		}else p[i]=i;
	}
	p[m-1]=n-l[m-1];
	for(int i=m-2;i>=0;--i)
		if(p[i+1]-p[i]>l[i]) p[i]=p[i+1]-l[i];
	if(p[0]!=0){
		puts("-1");
		exit(0);
	}
	for(int i=0;i<m;++i) printf("%d ",p[i]+1); puts("");
	return 0;
}
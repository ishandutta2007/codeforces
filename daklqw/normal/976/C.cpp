#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
#define MAXN 300010
int n,xs[MAXN],ys[MAXN],rk[MAXN];
map<int,int>m;
inline bool cmp(int a,int b){
	return xs[a]<xs[b];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d%d",&xs[i],&ys[i]);
		if(m[xs[i]]){
			if(ys[m[xs[i]]]>ys[i])cout<<i<<" "<<m[xs[i]]<<endl;
			else cout<<m[xs[i]]<<" "<<i<<endl;
			return 0;
		}
		m[xs[i]]=i;
		rk[i]=i;
	}
	sort(rk+1,rk+1+n,cmp);
	for(int i=2;i<=n;++i)
		if(ys[rk[i]]<=ys[rk[i-1]]){
			cout<<rk[i]<<" "<<rk[i-1]<<endl;
			return 0;
		}
	cout<<"-1 -1"<<endl;
	return 0;
}
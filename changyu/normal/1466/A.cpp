#include<bits/stdc++.h>
const int N=1e5+3;
int n,a[N];std::set<int>s; 
signed main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)
	  for(int j=1;j<i;j++)s.insert(std::abs(a[i]-a[j]));
	printf("%d\n",s.size()),s.clear();
	}return 0;
}
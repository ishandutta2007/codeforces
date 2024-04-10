#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,m,i,j,t,a[1005],c[1005];
vector<int> res;
int mex()
{
	int i;
	memset(c,0,sizeof(c));
	rep(i,n) c[a[i]]++;
	i=0;while(c[i])i++;
	return i;
}
int main()
{
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);res.clear();
		rep(i,n) scanf("%d",&a[i]);
		rep(i,n){
			int t=mex();
			if(t==n){
				rep(j,n){
					if(a[j]!=j-1){
						a[j]=t;
						res.push_back(j);
						break;
					}
				}
				if(j>n) break;
				i--;
				continue;
			}
			a[t+1]=t;
			res.push_back(t+1);
		}
		printf("%d\n",res.size());
		for(i=0;i<res.size();i++){
			printf("%d ",res[i]);
		}puts("");
	}
	return 0;
}
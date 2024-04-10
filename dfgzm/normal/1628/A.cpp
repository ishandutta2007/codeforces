#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define mid (l+r>>1)
using namespace std;
const int maxn=200005,maxt=maxn<<2;
int n,T;
int a[maxn],tot[maxn],now[maxn];
vector<int>ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans.clear();
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),tot[a[i]]++;
		int all=0;
		while(tot[all])
			all++;
		int nw=0;
		for(int i=1;i<=n;i++){
			now[a[i]]++;
			while(now[nw])
				nw++;
			if(nw==all){
				ans.push_back(all);
				for(int j=0;j<=nw;j++){
					tot[j]-=now[j],now[j]=0;
					if(tot[j]==0)
						all=min(all,j);
				}
				nw=0;
			}
		}
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++)
			printf("%d%c",ans[i],i==ans.size()-1? '\n':' ');
		for(int i=0;i<=n;i++)
			tot[i]=now[i]=0;
	}
	return 0;
}
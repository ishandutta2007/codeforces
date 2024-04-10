#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,sums[100010],size[100010],idx;
bool vis[100010];
long long ans=0,ans2=0;
inline long long pows(int x){return 1LL*x*x;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&sums[i]),size[i]=1;
	for(int i=1;i<=n;++i)
		if(!vis[i]){
			vis[i]=true;
			++idx;
			int t=sums[i];
			while(t!=i){
				vis[t]=true;++size[idx];t=sums[t];
			}
		}
	sort(size+1,size+1+idx);
	if(idx==1)printf("%I64d\n",pows(size[1]));
	else{
		for(int i=idx;i&&size[i];--i)ans2+=pows(size[i]);
		ans+=pows(size[idx]+size[idx-1]);
		for(int i=idx-2;i&&size[i];--i)ans+=pows(size[i]);
		printf("%I64d\n",max(ans,ans2));
	}
	return 0;
}
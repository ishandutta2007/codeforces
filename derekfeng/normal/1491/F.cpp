#include<bits/stdc++.h>
using namespace std;
int T,n,F;
vector<int>ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=2;i<=n;i++){
			printf("? 1 %d\n%d\n",i-1,i);
			for(int j=1;j<i;j++)printf("%d ",j);puts("");fflush(stdout);
			scanf("%d",&F);
			if(F){
				ans.clear();
				for(int j=i+1;j<=n;j++){
					printf("? 1 1\n%d\n%d\n",i,j);fflush(stdout);
					scanf("%d",&F);
					if(!F)ans.push_back(j);
				}
				int l=0,r=i;
				while(r>l+1){
					int mid=(l+r)/2;
					printf("? 1 %d\n%d\n",mid,i);
					for(int j=1;j<=mid;j++)printf("%d ",j);puts("");fflush(stdout);
					scanf("%d",&F);
					if(F)r=mid;
					else l=mid;
				}
				for(int j=1;j<i;j++)if(j!=r)ans.push_back(j);
				printf("! %d\n",ans.size());
				for(auto x:ans)printf("%d ",x);puts("");fflush(stdout);break;
			}
		}
	}
}
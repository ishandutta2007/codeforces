#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int key; scanf("%d",&key);
		int ans=1;
		while(key>0) key-=key&-key,ans<<=1;
		printf("%d\n",ans);
	}
	return 0;
}
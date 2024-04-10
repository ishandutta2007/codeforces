#include<stdio.h>
#include<set>
using namespace std;
#define R register int
set<int>S[200001];
inline bool Check(int x){
	return S[x].empty()||*S[x].rbegin()<x;
}
int main(){
	int n,m,x,y,ans=0,opt;
	scanf("%d%d",&n,&m);
	for(R i=0;i!=m;i++){
		scanf("%d%d",&x,&y);
		S[x].insert(y);
		S[y].insert(x);
	}
	for(R i=1;i<=n;i++){
		if(Check(i)==true){
			ans++;
		}
	}
	scanf("%d",&m);
	for(R i=0;i!=m;i++){
		scanf("%d",&opt);
		if(opt==3){
			printf("%d\n",ans);
		}else{
			scanf("%d%d",&x,&y);
			if(Check(x)==true){
				ans--;
			}
			if(Check(y)==true){
				ans--;
			}
			if(opt==1){
				S[x].insert(y);
				S[y].insert(x);
			}else{
				S[x].erase(y);
				S[y].erase(x);
			}
			if(Check(x)==true){
				ans++;
			}
			if(Check(y)==true){
				ans++;
			}
		}
	}
	return 0;
}
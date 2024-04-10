#include<bits/stdc++.h>
using namespace std;
int n;
int Ask(int x){
	printf("? %d\n",x);fflush(stdout);
	int tmp;scanf("%d",&tmp);fflush(stdout);
	return tmp;
}
int main(){
	scanf("%d",&n);
	int l=0,r=1e7;
	while(r>l+1){
		int md=(l+r)>>1;
		if(Ask(md)==1)r=md;
		else l=md;
	}
	int ans=r;
	for(int i=1;i<=n;i++){
		int tmp=Ask(r/i);
		if(tmp>0&&tmp*(r/i)<=ans)ans=tmp*(r/i);
	}
	printf("! %d",ans);
}
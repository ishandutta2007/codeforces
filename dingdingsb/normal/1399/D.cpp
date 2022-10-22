 #pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
int t,n;
char str[200000+10];
multiset<int >s[2];
int ans[200000+10],tot;
signed main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		scanf("%s",str+1);
		ans[1]=tot=1;
		s[0].clear();
		s[1].clear();
		s[str[1]-'0'].insert(1);
		for(int i=2;i<=n;i++){
			int n=str[i]-'0';
			int f=n^1;
			if(s[f].size()){
				int fr=*s[f].begin();
				s[f].erase(s[f].begin());
				s[n].insert(i);
				ans[i]=ans[fr]; 
			}
			else{
				ans[i]=++tot;
				s[n].insert(i);
			}
		}
		printf("%d\n",tot);
		for(int i=1;i<=n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	} 
	return 0;
}
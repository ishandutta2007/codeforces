#include<bits/stdc++.h>
using namespace std;
vector<int> a[3];
int main(){
	for(int i=1;i<=3;++i){
		int x;  scanf("%d",&x);
		char c=getchar();
		while(c<'a'||c>'z') c=getchar();
		if(c=='s') a[0].push_back(x);
		else if(c=='m') a[1].push_back(x);
		else a[2].push_back(x);
	}
	int ans=2;
	for(int i=0;i<3;++i){
		sort(a[i].begin(),a[i].end());
		if(a[i].size()==3){
			if(a[i][0]==a[i][1]&&a[i][1]==a[i][2])
				ans=min(ans,0);
			if(a[i][0]+1==a[i][1]&&a[i][1]+1==a[i][2])
				ans=min(ans,0);
			if(a[i][0]==a[i][1]||a[i][1]==a[i][2])
				ans=min(ans,1);
			if(a[i][0]+1==a[i][1]||a[i][1]+1==a[i][2])
				ans=min(ans,1);
			if(a[i][0]+2==a[i][1]||a[i][1]+2==a[i][2])
				ans=min(ans,1);
		}else if(a[i].size()==2){
			if(a[i][0]==a[i][1]) ans=min(ans,1);
			if(a[i][0]+1==a[i][1]) ans=min(ans,1);
			if(a[i][0]+2==a[i][1]) ans=min(ans,1);
		}
	}
	printf("%d\n",ans);
	return 0;
}
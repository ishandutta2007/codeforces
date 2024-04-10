#include<bits/stdc++.h>
using namespace std;
int n;
int a[103][103];
vector<vector<int> >ans;
int pas[103];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int x;scanf("%d",&x);
			a[i][x]++;
		}
	}
	for(;;){
		bool ok=1;
		for(int i=1;i<=n&&ok;i++)
			for(int j=1;j<=n;j++)ok&=a[i][j]>0;
		if(ok)break;
		memset(pas,0,sizeof(pas));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)if(a[i][j]>1){
				pas[i]=j;break;
			}
		}
		for(int t=0;t<2;t++){
			for(int i=1;i<=n;i++)if(!pas[i]){
				int lst=i>1?i-1:n;
				if(pas[lst])pas[i]=pas[lst];
			}
		}
		vector<int>ad;
		for(int i=1;i<=n;i++){
			ad.push_back(pas[i]);
			a[i][pas[i]]--;
			int lst=i>1?i-1:n;
			a[i][pas[lst]]++;
		}
		ans.push_back(ad);
	}
	for(int i=2;i<=n;i++){
		vector<int>v;
		for(int j=1,cur=i;j<=n;j++,cur=cur%n+1)v.push_back(cur);
		while(v[0]!=1){
			ans.push_back(v);
			vector<int>nv;
			nv.push_back(v[n-1]);
			for(int i=0;i<n-1;i++)nv.push_back(v[i]);
			v=nv;
		}
	}
	printf("%d\n",ans.size());
	for(auto v:ans){
		for(auto x:v)printf("%d ",x);
		puts("");
	}
}
#include<bits/stdc++.h>
using namespace std;
int n;
int cnt[200005];
vector<int>res,cur;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){int x;scanf("%d",&x),cnt[x]++;}
	for(int i=1,j,k;i<=2e5;i++)if(cnt[i]>0){
		cur.clear();
		for(j=i+1;cnt[j]>1;j++);
		if(cnt[j]==0)j--;
		for(k=i;k<=j;k++)cur.push_back(k);
		for(k=j;k>=i;k--)for(int s=0;s<cnt[k]-1;s++)cur.push_back(k);
		if(cur.size()>res.size())res=cur;
		bool flg=i!=j;
		i=j;
		if(cnt[i]==1&&flg)i--;
	}
	printf("%d\n",res.size());
	for(auto x:res)printf("%d ",x);
}
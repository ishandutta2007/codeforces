#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#define maxn 1000009
using namespace std;
map<pair<int,int>,pair<int,int>>mp;
int n,a[maxn][5],cur,ans1,ans2;
void doit(int a,int b,int c,int x,int y){
	int tmp=min(a,b);
	tmp=min(tmp,c);
	if(tmp>cur){
		cur=tmp;
		ans1=x;
		ans2=y;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++)
			scanf("%d",&a[i][j]);
		for(int j=0;j<3;j++)
			for(int k=j+1;k<3;k++)
				mp[make_pair(a[i][j],a[i][k])]=make_pair(0,0);
		sort(a[i],a[i]+3);
	}
	for(int i=1;i<=n;i++){
		int x=mp[make_pair(a[i][0],a[i][1])].first;
		if(x){
			doit(a[i][0],a[i][1],a[i][2]+mp[make_pair(a[i][0],a[i][1])].second,i,x);
		}
		x=mp[make_pair(a[i][0],a[i][2])].first;
		if(x){
			doit(a[i][0],a[i][2],a[i][1]+mp[make_pair(a[i][0],a[i][2])].second,i,x);
		}
		x=mp[make_pair(a[i][1],a[i][2])].first;
		if(x){
			doit(a[i][1],a[i][2],a[i][0]+mp[make_pair(a[i][1],a[i][2])].second,i,x);
		}
		if(mp[make_pair(a[i][0],a[i][1])].second<a[i][2]){
			mp[make_pair(a[i][0],a[i][1])].second=a[i][2];
			mp[make_pair(a[i][0],a[i][1])].first=i;
		}
		if(mp[make_pair(a[i][0],a[i][2])].second<a[i][1]){
			mp[make_pair(a[i][0],a[i][2])].second=a[i][1];
			mp[make_pair(a[i][0],a[i][2])].first=i;
		}
		if(mp[make_pair(a[i][1],a[i][2])].second<a[i][0]){
			mp[make_pair(a[i][1],a[i][2])].second=a[i][0];
			mp[make_pair(a[i][1],a[i][2])].first=i;
		}
	}
	int cur2=0,ans3=0;
	for(int i=1;i<=n;i++){
		if(a[i][0]>cur2){
			cur2=a[i][0];
			ans3=i;
		}
	}
	if(cur2>=cur){
		printf("1\n");
		printf("%d\n",ans3);
	}
	else{
		printf("2\n");
		printf("%d %d\n",ans2,ans1);
	}
	//system("pause");
	return 0;
}
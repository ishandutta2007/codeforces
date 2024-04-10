#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int t,n,r[50005][10],book[50005];
int id[50005];
int num(int a,int b){
	int cnt=0;
	for (int i=1;i<=5;i++)
		if (r[a][i]<r[b][i])cnt++;
	return cnt;
}
bool cmp(int a,int b){
	int cnt=num(a,b);
	if (cnt>=3)return 1;
	return 0;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)
			for (int j=1;j<=5;j++)scanf("%d",&r[i][j]);
		for (int i=1;i<=n;i++)id[i]=i;
		sort(id+1,id+1+n,cmp);
		int fg=1;
		for (int i=2;i<=n;i++)
			if (num(id[i],id[1])>=3)fg=0;
		if (fg==0)puts("-1");
		else printf("%d\n",id[1]);
		for (int i=1;i<=n;i++)book[i]=0;
	}
	return 0;
}
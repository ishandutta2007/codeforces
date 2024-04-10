#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e5+100;
vector<int> ans[MAX];
int ansnum=0;
int n;
int rk[MAX];
int a[MAX];
bool used[MAX];
bool cmp(int x,int y){
	return a[x]<a[y];
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
		rk[i]=i;
		used[i] = false;
	}
	sort(rk+0,rk+n,cmp);
	for (int i=0;i<n;i++){
		if (!used[i]){
			int temp=i;
			while (!used[temp]){
				ans[ansnum].push_back(temp);
				used[temp] = true;
				temp = rk[temp];
			}
			ansnum++;
		}
	}
	printf("%d\n",ansnum);
	for (int i=0;i<ansnum;i++){
		printf("%d ",ans[i].size());
		for (int x:ans[i]){
			printf("%d ",x+1);
		}
		printf("\n");
	}
	return 0;
}
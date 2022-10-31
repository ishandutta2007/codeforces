#include<bits/stdc++.h>
using namespace std;

int bas[1000];
int ans[30];
bool flag = false;
priority_queue<int> pq;
void dfs(int index,int low,int tar){
	if (index==27){
		return ;
	}
	if (flag){
		return;
	}
	if (tar==0){
		flag = true;
		for (int i=0;i<index;i++){
			for (int j=0;j<ans[i]+1;j++){
				printf("%c",i+'a');
			}
		}
		printf("\n");
	}
	for (int i=low;i<=447;i++){
		if (tar>=bas[i]){
			ans[index] = i;
			dfs(index+1,i,tar-bas[i]);
		}
	}
}
int calc(int x){
	while (!pq.empty()) pq.pop();
	for (int i=0;i<x;i++){
		pq.push(1);
	}
	int res =0;
	while (pq.size()>=2){
		int cnt1 = pq.top();
		pq.pop();
		int cnt2 = pq.top();
		pq.pop();
//		cout<<cnt1<<" "<<cnt2<<endl;
		res+=cnt1*cnt2;
		pq.push(cnt1+cnt2);
	}
	return res;
}
int main(){
	int n;
	scanf("%d",&n);
	if (n==0){
		printf("a\n");
		return 0;
	}
	for (int i=1;i<=447;i++){
		bas[i] = calc(i+1);
//		cout<<"bas["<<i<<"]"<<bas[i]<<endl;
	}
	dfs(0,1,n);

}
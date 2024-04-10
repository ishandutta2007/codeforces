#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5+100;
int a[maxn];
vector<int> ans[maxn];
int top[maxn];
int tot;
int n;

int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	tot=1;
	ans[0].push_back(a[0]);
	top[0]=a[0];
	for (int i=1;i<n;i++){
		int val = a[i];
		bool flag = false;
		int l=0;int r=tot-1;
		while (r-l>1){
			int mid =l+r >>1;
			if (top[mid]<val){
				r=mid;
			}else{
				l=mid;
			}
		}
		int index =top[l]<val?l:r;
//		cout<<i<<" "<<index<<endl;
		if (top[index]<val){
			ans[index].push_back(val);
			top[index]=val;
		}else{
			ans[tot++].push_back(val);
			top[tot-1]=val;
		}
	}
	for (int i=0;i<tot;i++){
		for (int j=0;j<ans[i].size();j++){
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
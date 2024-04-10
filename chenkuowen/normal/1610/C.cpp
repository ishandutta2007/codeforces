#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
int a[N],b[N],n;
bool solve(int mid){
	int ans=0;
	for(int i=n;i>=1;--i)
		if(ans<=a[i]&&ans>=mid-1-b[i])
			++ans;
	return ans>=mid;
}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d%d",&a[i],&b[i]);
		int left=0,right=n;
		while(left<right){
			int mid=left+right+1>>1;
			if(solve(mid)) left=mid;
			else right=mid-1;
		}
		printf("%d\n",left);
	}
	return 0;
}
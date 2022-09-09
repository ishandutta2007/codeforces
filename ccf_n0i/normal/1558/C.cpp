#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,i,j,a[2025];
vector<int> ans;
void rev(int x){
	reverse(a+1,a+x+1);
	ans.push_back(x);
}
void solve(){
	scanf("%d",&n);
	rep(i,n){
		scanf("%d",&a[i]);
	}
	rep(i,n){
		if((a[i]^i)&1){
			puts("-1");
			return;
		}
	}
	ans.clear();
	while(n>1){
		rep(i,n) if(a[i]==n) break;
		rev(i);
		rep(i,n) if(a[i]==n-1)break;
		rev(i-1);rev(i+1);rev(3);
		rev(n);n-=2;
	}
	printf("%d\n",ans.size());
	rep(i,ans.size()){
		printf("%d",ans[i-1]);
		if(i==ans.size())puts("");else putchar(' ');
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		solve();
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=5+1e6;
int a[N],b[N],cnt[N];
bool solve(int n){
	for(int i=1;i<=n;++i) cnt[i]=0;
	for(int i=n,j=n;j>=1;--j){
		if(a[i]!=b[j]){
			if(j==n||b[j]!=b[j+1]){
				if(cnt[a[i]]>0) --cnt[a[i]],--i,++j;
				else return false;
			}else{
				cnt[b[j]]++;
			}
		}else --i;
	}
	return true;

}
int main(){
	int T; scanf("%d",&T);
	while(T--){
		int n; scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;++i) scanf("%d",&b[i]);
		for(int i=1;i<=n;++i) cnt[i]=0;
		if(solve(n)) puts("YES");
		else puts("NO");
	}
	return 0;
}
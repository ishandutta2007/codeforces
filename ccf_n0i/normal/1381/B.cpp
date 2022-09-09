#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int f[4005],a[4005],n,i,j,t;
vector<int> s;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		rep(i,n+n){
			scanf("%d",&a[i]);
		}
		s.clear();
		int lst=1;
		rep(i,n+n)if(i>1){
			if(a[i]>a[lst]){
				s.push_back(i-lst);
				lst=i;
			}
		}
		s.push_back(n+n-lst+1);
		for(i=0;i<=n;i++)f[i]=0;
		f[0]=1;
		for(i=0;i<s.size();i++){
			for(j=n;j>=s[i];j--){
				f[j]|=f[j-s[i]];
			}
		}
		puts(f[n]?"YES":"NO");
	}
	return 0;
}
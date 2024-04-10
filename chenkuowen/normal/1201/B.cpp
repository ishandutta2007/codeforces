#include<bits/stdc++.h>
using namespace std;
vector<int> a;
typedef long long ll;
int main(){
	int n; scanf("%d",&n); a.resize(n+1);
	ll sum=0;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),sum+=a[i];
	for(int i=1;i<=n;++i)
		if(a[i]>sum>>1){
			puts("NO");
			return 0;
		}
	if(sum&1){
		puts("NO");
		return 0;
	}
	puts("YES");
	return 0;
}
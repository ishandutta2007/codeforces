#include<bits/stdc++.h>
using namespace std;
long long n,x;
long long a[100000];
vector <long long> ans;
void dfs(long long pos,long long maxx){
	if (pos-1>=0&&pos-1!=maxx) dfs(pos-1,maxx); else
	if (pos-2>=0&&pos-2!=maxx) dfs(pos-2,maxx);
	ans.push_back(1<<pos);
	if (pos-1>=0&&pos-1!=maxx) dfs(pos-1,maxx); else 
	if (pos-2>=0&&pos-2!=maxx) dfs(pos-2,maxx);
}
int main(){
	scanf("%lld%lld",&n,&x);
	long long maxx=0;
	for (long long i=0;i<=18;++i){
		if ((1ll<<i)<=x) maxx=i;
	}
	for (long long i=n-1;i>=0;i--){
		if (i!=maxx){
			dfs(i,maxx);
			break;
		}
	}
	printf("%d\n",ans.size());
	for (long long i=0;i<ans.size();++i) printf("%d ",ans[i]);
}
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int n,m,a[N],T;bool vis[N];
void solve(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)vis[i]=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),a[i]+=i,a[i]=(a[i]%n+n)%n,vis[a[i]]=1;
	for(int i=0;i<n;i++)if(!vis[i]){puts("NO");return;}
	puts("YES");
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
    return 0;
}
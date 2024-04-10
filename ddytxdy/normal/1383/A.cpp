#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=1e5+50;
int n,T,f[N],ans;char a[N],b[N];bool vis[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void solve(){
	scanf("%d%s%s",&n,a+1,b+1);ans=0;
	for(int i=0;i<26;i++)vis[i]=0,f[i]=i;
	for(int i=1;i<=n;i++)
		if(a[i]>b[i]){puts("-1");return;}
		else if(a[i]<b[i]){
			int x=find(a[i]-'a'),y=find(b[i]-'a');
			if(x!=y)ans++,f[x]=y;
		}
	cout<<ans<<endl;
}
int main(){
	scanf("%d",&T);
	while(T--)solve();
	return 0;
}
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=500005,mod=1000000007;
int T,n,m,a,b,c,d,ans;
int v[maxn],tot[maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&v[i]),v[i]=abs(v[i]),tot[v[i]]++;
		for(int i=0;i<=100;i++){
			if(i==0&&tot[i]){
				ans++;
				continue;
			}
			if(tot[i]>2)
				ans+=2;
			else ans+=tot[i];
		}
		printf("%d\n",ans);
		for(int i=0;i<=100;i++)
			tot[i]=0;
	}
	return 0;
}
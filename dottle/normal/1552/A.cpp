#include<bits/stdc++.h>
const int N=200005;
using namespace std;

int t,n;
char s[N],p[N]; 

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%s",&n,s);
		for(int i=0;i<n;i++)p[i]=s[i];
		sort(s,s+n);
		int ans=0;
		for(int i=0;i<n;i++)if(p[i]!=s[i])ans++; 
		printf("%d\n",ans);
	}
}
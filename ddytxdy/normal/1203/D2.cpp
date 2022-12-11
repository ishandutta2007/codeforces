#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
char s[N],t[N];int ls,lt,p1[N],p2[N],ans;
int main(){
	scanf("%s%s",s+1,t+1);ls=strlen(s+1);lt=strlen(t+1);p1[0]=0;p2[lt+1]=ls+1;
	for(int i=1,j=0;i<=ls;i++)s[i]==t[j+1]?p1[++j]=i:0;
	for(int i=ls,j=lt+1;i;i--)s[i]==t[j-1]?p2[--j]=i:0;
	for(int i=0;i<=lt;i++)ans=max(ans,p2[i+1]-p1[i]-1);
	printf("%d\n",ans);
	return 0;
}
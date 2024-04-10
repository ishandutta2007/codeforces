#include<bits/stdc++.h>
std::map<int,int>mp,pm; 
const int N=2e5+3;
int n,a[N],t[N];
bool Cmp(const int&i,const int&j){return a[i]<a[j];}
signed main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),t[i]=i;
	std::sort(t+1,t+1+n,Cmp);
	for(int i,k,j=2;j<=n;j++){
	  i=t[j],k=t[j-1];
	  if(mp[a[i]-a[k]]){
		if(mp[a[i]-a[k]]<j-1)return 0*printf("YES\n%d %d %d %d\n",i,t[mp[a[i]-a[k]]-1],t[mp[a[i]-a[k]]],k);
	  }
	  else mp[a[i]-a[k]]=j;
	}
	mp.clear();
	for(int i=1,k;i<=n;i++)
	  for(int j=n,l;j>i;j--){
		k=t[i],l=t[j];
		if(mp[a[k]+a[l]]){
		  if(mp[a[k]+a[l]]<i&&pm[a[k]+a[l]]>j)return 0*printf("YES\n%d %d %d %d\n",k,l,t[mp[a[k]+a[l]]],t[pm[a[k]+a[l]]]);
		}
		else mp[a[k]+a[l]]=i,pm[a[k]+a[l]]=j;
	  }
	return 0*puts("NO");
}
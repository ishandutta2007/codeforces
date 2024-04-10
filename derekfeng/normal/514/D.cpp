#include<bits/stdc++.h>
using namespace std;
int n,m,K,ans,res[5];
int a[100004][5];
multiset<int>s[5];
int calc(){
	int sum=0;
	for(int i=0;i<m;i++)sum+=(*s[i].rbegin());
	return sum;
}
int main(){
	scanf("%d%d%d",&n,&m,&K);
	for(int i=0;i<m;i++)s[i].insert(0);
	int l=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++)scanf("%d",&a[i][j]),s[j].insert(a[i][j]);
		while(calc()>K){l++;for(int j=0;j<m;j++)s[j].erase(s[j].find(a[l][j]));}
		if(i-l>ans){ans=i-l;for(int j=0;j<m;j++)res[j]=(*s[j].rbegin());}
	}
	for(int i=0;i<m;i++)printf("%d ",res[i]);
}
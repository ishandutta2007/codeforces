#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n,k,s[300005];
struct node{
	int ch,id; 
}a[300005]; 
bool cmp(node a,node b){
	return a.ch>b.ch;
}
int ans,book[300005],now;
int main(){
//	freopen("1197C.in","r",stdin);
//	freopen("1197C.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)scanf("%d",&s[i]);
	for (int i=1;i<n;i++){
		a[i].ch=s[i+1]-s[i],a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=k-1;i++)book[a[i].id]=1;
	now=s[1];
	for (int i=1;i<=n;i++){
		if (book[i-1]==1)now=s[i]; 
		if (book[i]==1)ans+=s[i]-now,now=s[i];
	}
	ans+=s[n]-now;
	cout<<ans<<endl;
}
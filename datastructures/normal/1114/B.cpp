#include <iostream>
#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;
struct node{
	int val,id;
}a[1000005];
inline bool cmp(node a,node b){
	return a.val>b.val; 
}
int n,m,k,c[1000005];
signed main(){
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++)scanf("%lld",&a[i].val),a[i].id=i;
	sort(a+1,a+1+n,cmp);
	int sum=0;
	for (int i=1;i<=m*k;i++)sum+=a[i].val,c[a[i].id]=1;
	cout<<sum<<endl;
	int tot=0;
	for (int i=1;i<=n;i++){
		int j=i,now=0;
		while(now<m&&j<=n){
			now+=c[j];
			j++;
		}
		j--;
		printf("%lld ",j);
		++tot;
		if (tot==k-1)break;
		i=j;
	}
	return 0;
}
//00101001011
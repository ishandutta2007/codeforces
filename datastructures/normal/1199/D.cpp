#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,a[200005],t,flag,p,x,tag[200005],mx[200005];
signed main(){
	cin>>n;
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	cin>>t;
	for (int i=1;i<=t;i++){
		scanf("%d",&flag);
		if (flag==1){
			scanf("%d%d",&p,&x);
			a[p]=x;
			tag[p]=i;
		}
		else{
			scanf("%d",&x);
			mx[i]=x;
		}
	}
	for (int i=t;i>=0;i--)mx[i]=max(mx[i],mx[i+1]);
	for (int i=1;i<=n;i++)a[i]=max(a[i],mx[tag[i]]);
	for (int i=1;i<=n;i++)printf("%d ",a[i]);
	cout<<endl;
	return 0;
}
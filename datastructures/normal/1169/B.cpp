#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int n,m,a[300005],b[300005];
int x,y,flag,tot;
inline void check(){
	tot=0;
	for (int i=1;i<=n;i++)
		if (a[i]==x||a[i]==y||b[i]==x||b[i]==y)tot++;
	if (tot==n)flag=1;
	return;
}
signed main(){
	cin>>m>>n;
	for (int i=1;i<=n;i++)scanf("%d%d",&a[i],&b[i]);
	x=a[1],y=0;
	check();
	for (int i=1;i<=n;i++){
		if (a[i]!=x&&b[i]!=x){
			y=a[i];
			check();
			y=b[i];
			check();
			break;
		}
	}
	x=b[1],y=0;
	check();
	for (int i=1;i<=n;i++){
		if (a[i]!=x&&b[i]!=x){
			y=a[i];
			check();
			y=b[i];
			check();
			break;
		}
	}
	if (flag==1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
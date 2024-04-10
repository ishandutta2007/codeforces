/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000,M=200000;
int a[M+1];
int d[N+1];
signed main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<m;i++){
		int x=a[i],y=a[i+1];
		if(x==y)continue;
		if(x>y)swap(x,y);
		d[1]+=y-x;d[x]-=y-x;
		d[x]+=y-1;d[x+1]-=y-1;
		d[x+1]+=y-(x+1);d[y]-=y-(x+1);
		d[y]+=(x+1)-1;d[y+1]-=(x+1)-1;
		d[y+1]+=(y+1)-(x+1);
	}
	int now=0;
	for(int i=1;i<=n;i++)now+=d[i],cout<<now<<" ";
	return 0;
}
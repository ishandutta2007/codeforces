/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100000;
int n,qu;
int a[N+1];
int dif[N],Sum[N];
bool cmp(int x,int y){return x>y;}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)dif[i]=a[i+1]-a[i];
	sort(dif+1,dif+n,cmp);
//	for(int i=1;i<n;i++)cout<<dif[i]<<" ";puts("");
	for(int i=1;i<n;i++)Sum[i]=Sum[i-1]+dif[i];
	cin>>qu;
	while(qu--){
		int x,y;
		cin>>x>>y;
		x=y-x+1;
		int ans=a[n]+x-a[1];
		int fd=lower_bound(dif+1,dif+n,x,cmp)-dif-1;
		ans-=Sum[fd]-fd*x;
		cout<<ans<<" ";
	}
	return 0;
}
/*1
6
3 1 4 1 5 9
3
7 7
0 2
8 17
*/
/*2
2
1 500000000000000000
2
1000000000000000000 1000000000000000000
0 1000000000000000000
*/
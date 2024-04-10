#include <iostream>
#include <cstdio> 
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;
int t,n,a[300005],flag;
signed main(){
	cin>>t;
	while(t--){
		cin>>n;
		for (int i=1;i<=n;i++)scanf("%d",&a[i]);
		int x=1,y=n;
		while(a[x]>=x-1&&x<=n)x++;
		x--;
		while(a[y]>=n-y&&y>=1)y--;
		y++;
		if (x>=y)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
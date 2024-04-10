/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	int n,p,w,d;
	cin>>n>>p>>w>>d;
	for(int i=0;i<=1000000;i++)if((p-d*i)%w==0){
		int x=(p-d*i)/w,y=i,z=n-x-y;
		if(x>=0&&y>=0&&z>=0)return cout<<x<<" "<<y<<" "<<z,0;
	}
	puts("-1");
	return 0;
}
/*1
627936103814 4254617095171609 45205 1927
*/
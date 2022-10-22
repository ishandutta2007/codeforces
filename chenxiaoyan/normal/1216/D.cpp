/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int x,int y){return y?gcd(y,x%y):x;}
const int N=200000;
int n;
int a[N+1];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int z=abs(a[2]-a[1]);
	for(int i=2;i<n;i++)z=gcd(z,abs(a[i+1]-a[i]));
	int mx=*max_element(a+1,a+n+1),y=0;
	for(int i=1;i<=n;i++)y+=(mx-a[i])/z;
	cout<<y<<" "<<z;
	return 0;
}
/*1
3
3 12 6
*/
/*2
2
2 9
*/
/*3
7
2 1000000000 4 6 8 4 2
*/
/*4
6
13 52 0 13 26 52
*/
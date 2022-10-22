/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1500;
int n,qu;
int a[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	bool cnt=0;
	for(int i=1;i<=n;i++)for(int j=i+1;j<=n;j++)cnt^=a[i]>a[j];
	cin>>qu;
	while(qu--){
		int l,r;
		cin>>l>>r;
		int len=r-l+1;
		cnt^=len*(len-1)/2&1;
		puts(!cnt?"even":"odd");
	}
	return 0;
}
/*1
3
1 2 3
2
1 2
2 3
*/
/*2
4
1 2 4 3
4
1 1
1 4
1 4
2 3
*/
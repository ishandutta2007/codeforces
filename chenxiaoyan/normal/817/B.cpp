/*









 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100000;
int n;
int a[N+1];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int cnt1=0,cnt2=0,cnt3=0;
	for(int i=1;i<=n;i++)cnt1+=a[i]==a[1],cnt2+=a[i]==a[2],cnt3+=a[i]==a[3];
	if(a[1]==a[2]&&a[2]==a[3])cout<<1ll*cnt1*(cnt1-1)*(cnt1-2)/6;
	else if(a[1]==a[2]&&a[2]!=a[3])cout<<1ll*cnt1*(cnt1-1)/2*cnt3;
	else if(a[1]!=a[2]&&a[2]==a[3])cout<<1ll*cnt1*cnt3*(cnt3-1)/2;
	else cout<<1ll*cnt1*cnt2*cnt3;
	return 0;
}
/*1
4
1 1 1 1
*/
/*2
5
1 3 2 3 4
*/
/*3
6
1 3 3 1 3 2
*/
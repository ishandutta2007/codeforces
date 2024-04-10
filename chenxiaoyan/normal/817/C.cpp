/*









 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
bool chk(int x){
	int cpy=x;
//	cout<<x<<":";
	while(x)cpy-=x%10,x/=10;
//	cout<<cpy<<"\n";
	return cpy>=m;
}
signed main(){
	cin>>n>>m;
	int fst=LLONG_MAX;
	for(int i=62;~i;i--)if(fst-(1ll<<i)>=0&&chk(fst-(1ll<<i)))fst-=1ll<<i;
//	cout<<"fst="<<fst<<"\n";
	cout<<max(0ll,n-fst+1);
	return 0;
}
/*1
12 1
*/
/*2
25 20
*/
/*3
10 9
*/
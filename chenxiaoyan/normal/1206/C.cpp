/*








*/
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	if(n%2==0)return puts("NO"),0;
	puts("YES");
	for(int i=1;i<=2*n;i+=2)cout<<i+(i/2&1)<<" ";
	for(int i=1;i<=2*n;i+=2)cout<<i+!(i/2&1)<<" ";
	return 0;
}
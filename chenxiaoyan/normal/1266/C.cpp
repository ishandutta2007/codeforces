/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int lcm(int x,int y){return x*y/gcd(x,y);}
int n,m;
int main(){
	cin>>n>>m;
	if(n==1&&m==1)return puts("0"),0;
	if(n==1){
		for(int i=1;i<=m;i++)cout<<i+1<<" ";
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)cout<<i+1<<"\n";
		return 0;
	}
	for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)cout<<lcm(i,j+n)<<" ";puts("");}
	return 0;
}
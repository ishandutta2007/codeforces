/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int l,r;
bool chk(int x){
	bool vis[10]={};
	while(x){
		if(vis[x%10])return false;
		vis[x%10]=true;
		x/=10;
	}
	return true;
}
int main(){
	cin>>l>>r;
	for(int i=l;i<=r;i++)if(chk(i))return cout<<i,0;
	puts("-1");
	return 0;
}
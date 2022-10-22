/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int ppc(int x){return __builtin_popcount(x);}
const bool tb[][3]={{1,0,0},{0,1,0},{0,0,1},{1,1,0},{1,0,1},{0,1,1},{1,1,1}};
void mian(){
	int a[3];
	cin>>a[0]>>a[1]>>a[2];
	int ans=0;
	for(int i=0;i<1<<7;i++){
		int b[3]={};
		for(int j=0;j<7;j++)if(i&1<<j)for(int k=0;k<3;k++)b[k]+=tb[j][k];
		bool ok=true;
		for(int j=0;j<3;j++)ok&=b[j]<=a[j];
		if(ok)ans=max(ans,ppc(i));
	}
	cout<<ans<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian(); 
	return 0;
}
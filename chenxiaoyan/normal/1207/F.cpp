/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int SUM_SIZE=700;
const int n=500000;
int qu;
int a[n+1];
int sum[SUM_SIZE+1][SUM_SIZE+1];
int main(){
	cin>>qu;
	while(qu--){
		int tp,x,y;
		cin>>tp>>x>>y;
		if(tp==1){
			a[x]+=y;
			for(int i=1;i<=700;i++)
				sum[i][x%i]+=y;
		}
		else
			if(x<=700)cout<<sum[x][y]<<"\n";
			else{
				int ans=0;
				for(int i=y?y:x;i<=n;i+=x)ans+=a[i];
				cout<<ans<<"\n";
			}
	}
	return 0;
}
/*1
5
1 3 4
2 3 0
2 4 3
1 4 -4
2 1 0
*/
/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum;
int main(){
	cin>>n;
	while(n--){
		int x;
		cin>>x;
		sum+=x;
	}
	cin>>m;
	while(m--){
		int l,r;
		cin>>l>>r;
		if(l<=sum&&sum<=r)return cout<<sum,0;
		if(l>sum)return cout<<l,0;
	}
	puts("-1");
	return 0;
}
/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	cin>>n;
	int now=0;
	while(n--){
		int x;
		cin>>x;
		cout<<x+now<<" ";
		now=max(now,x+now);
	}
	return 0;
}
/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;
	cin>>x;
	double ans=0;
	for(int i=1;i<=x;i++)ans+=1./i;
	printf("%.20lf",ans);
	return 0;
}
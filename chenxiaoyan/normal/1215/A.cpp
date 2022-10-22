/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	if(c<d)swap(c,d),swap(a,b);
	cout<<((a*(c-1)+b*(d-1)>e?0:e-(a*(c-1)+b*(d-1))))<<" "<<(b*d>=e?e/d:b+(e-b*d)/c);
	return 0;
}
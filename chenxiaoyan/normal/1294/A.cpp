/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int mx=max(max(a,b),c);
	d-=3*mx-a-b-c;
	puts(d>=0&&!(d%3)?"YES":"NO");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian(); 
	return 0;
}
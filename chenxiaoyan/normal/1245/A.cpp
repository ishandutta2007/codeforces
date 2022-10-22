/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y){return y?gcd(y,x%y):x;}
void mian(){
	int a,b;
	cin>>a>>b;
	puts(gcd(a,b)==1?"finite":"infinite");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
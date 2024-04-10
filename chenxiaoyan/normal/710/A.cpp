/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	if(a=="a1"||a=="a8"||a=="h1"||a=="h8")puts("3");
	else if(a[0]=='a'||a[0]=='h'||a[1]=='1'||a[1]=='8')puts("5");
	else puts("8");
	return 0;
}
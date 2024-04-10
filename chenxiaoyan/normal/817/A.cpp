/*









 l l
*/
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,f;
int main(){
	cin>>a>>b>>c>>d>>e>>f;
	puts((a-c)%e==0&&(b-d)%f==0&&abs((a-c)/e%2)==abs((b-d)/f%2)?"YES":"NO");
	return 0;
}
/*1
0 0 0 6
2 3
*/
/*2
1 1 3 6
1 5
*/
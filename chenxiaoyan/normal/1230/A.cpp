/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
	cin>>a>>b>>c>>d;
	int sum=a+b+c+d;
	if(!(sum&1)&&(a==sum/2||b==sum/2||c==sum/2||d==sum/2||a+b==sum/2||a+c==sum/2||a+d==sum/2))puts("YES");
	else puts("NO");
	return 0;
}
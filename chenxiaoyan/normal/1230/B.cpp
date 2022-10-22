/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=200000;
int n,m;
char a[N+5];
int main(){
	cin>>n>>m>>a+1;
	if(n==1)return puts(m?"0":a+1),0;
	for(int i=1;i<=n&&m;i++){
		char shd=i==1?'1':'0';
		if(a[i]!=shd)a[i]=shd,m--;
	}
	puts(a+1);
	return 0;
}
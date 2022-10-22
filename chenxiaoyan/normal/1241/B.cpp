/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	string a,b;
	cin>>a>>b;
	int c=0,d=0;
	for(int i=0;i<a.size();i++)c|=1<<a[i]-'a';
	for(int i=0;i<b.size();i++)d|=1<<b[i]-'a';
	puts(c&d?"YES":"NO");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
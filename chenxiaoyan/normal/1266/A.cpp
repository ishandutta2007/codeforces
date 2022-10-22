/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
void mian(){
	string a;
	cin>>a;
	int sum=0;
	bool hav0=false;
	int evn=0;
	for(int i=0;i<a.size();i++)sum+=a[i]^48,hav0|=a[i]=='0',evn+=!((a[i]^48)%2);
	puts(sum==0||sum%3==0&&evn>=2&&hav0?"red":"cyan");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
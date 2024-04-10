/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
int n;
string a;
void mian(){
	cin>>n>>a;
	if(n&1){
		bool hav=false;
		for(int i=0;i<n;i+=2)hav|=(a[i]^48)%2==1;
		puts(hav?"1":"2");
	}
	else{
		bool hav=false;
		for(int i=1;i<n;i+=2)hav|=(a[i]^48)%2==0;
		puts(hav?"2":"1");
	}
}
int main(){
	int testnum=1;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
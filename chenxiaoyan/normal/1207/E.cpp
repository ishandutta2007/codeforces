/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
int x,ans;
int main(){
	cout<<"? ";
	for(int i=1;i<=100;i++)cout<<i<<(i<100?" ":"\n");
	cout.flush();
	cin>>x;
	for(int i=13;i>=7;i--)ans|=x&1<<i;
	cout<<"? ";
	for(int i=1;i<=100;i++)cout<<(i<<7)<<(i<100?" ":"\n");
	cout.flush();
	cin>>x;
	for(int i=6;~i;i--)ans|=x&1<<i;
	cout<<"! "<<ans<<"\n";
	cout.flush();
	return 0;
}
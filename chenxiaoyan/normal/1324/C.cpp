/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=200000;
int n;
char a[N+5];
void mian(){
	cin>>a+1;
	n=strlen(a+1);
	vector<int> pos;
	pos.pb(0);
	for(int i=1;i<=n;i++)if(a[i]=='R')pos.pb(i);
	pos.pb(n+1);
	int ans=0;
	for(int i=0;i+1<pos.size();i++)ans=max(ans,pos[i+1]-pos[i]);
	cout<<ans<<"\n";
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
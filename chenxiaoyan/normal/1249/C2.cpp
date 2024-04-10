/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pf push_front
#define pb push_back
void mian(){
	int n;
	cin>>n;
	deque<int> pw;
	while(n)pw.pb(n%3),n/=3;
	reverse(pw.begin(),pw.end());
//	for(int i=0;i<pw.size();i++)cout<<pw[i]<<" ";puts("!");
	while(true){
		int fd=-1;
		for(int i=0;i<pw.size();i++)if(pw[i]==2){fd=i;break;}
		if(!~fd)break;
		for(int i=fd;i<pw.size();i++)pw[i]=0;
		if(fd==0)fd++,pw.pf(0ll);
		pw[fd-1]++;
	}
	int now=1,ans=0;
	for(int i=pw.size()-1;~i;i--)ans+=pw[i]*now,now*=3;
	cout<<ans<<"\n";
}
signed main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=100;
int n;
int a[N+1];
int cnt[N+1];
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n;i++)cnt[a[i]]++;
	int fst=0;
	for(int i=0;i<=100;i++)if(cnt[i]<2){fst=i;break;}
	for(int i=fst;i<=100;i++)if(cnt[i]<1)return cout<<fst+i<<"\n",void();
	if(fst)cout<<fst+101<<"\n";
	else cout<<202<<"\n";
}
int main(){
	int testnum=1;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
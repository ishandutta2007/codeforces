/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
const int inf=0x3f3f3f3f;
const int N=200000;
int n;
int a[N+1];
int b[N+1],c[N+1];
pair<int,int> mX[N+2],mN[N+2];
void mian(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)b[i]=a[i]+i,c[i]=a[i]-i;
	mX[n+1]=mp(-inf,0);mN[n+1]=mp(inf,0);
	for(int i=n;i;i--){
		mX[i]=max(mX[i+1],mp(c[i],i));
		if(mX[i+1].X>c[i]){printf("yes\n%d %d\n",i,mX[i+1].Y);return;}
		mN[i]=min(mN[i+1],mp(b[i],i));
		if(mN[i+1].X<b[i]){printf("yes\n%d %d\n",i,mN[i+1].Y);return;}
	}
	puts("no");
}
int main(){
	int testnum;
	cin>>testnum;
	while(testnum--)mian();
	return 0;
}
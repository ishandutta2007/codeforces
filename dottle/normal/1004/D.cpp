#include<bits/stdc++.h>
//#define int long long
const int N=1.1e6;
using namespace std;

int n,m,c[N],d[N],mx,x,y,t;

void chk(){
	memset(d,0,sizeof(d));
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)d[abs(i-x)+abs(j-y)]++;
	for(int i=1;i<=t;i++)if(c[i]!=d[i])return;
	cout<<n<<' '<<m<<endl<<x<<' '<<y<<endl;
	exit(0);
}

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	for(int i=1,j;i<=t;i++)cin>>j,c[j]++,mx=max(mx,j);
	for(int i=1;i<=t;i++)if(c[i]!=i*4){x=i;break;}
	for(int i=1;i<=t;i++)
		if(t%i==0){
			n=i,m=t/i;
			y=n+m-mx-x;
			chk();
		}
	cout<<-1;
}
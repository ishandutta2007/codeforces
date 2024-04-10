/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define X first
#define Y second
#define mp make_pair
const int N=100000;
int n;
int a[N+1],b[N+1],c[N+1],d[N+1],e[N+1],f[N+1];
const int hmod1=998244353,hmod2=1000000007;
int Sum1[N+1],Prod1[N+1],Sum2[N+1],Prod2[N+1],suM1[N+1],proD1[N+1],suM2[N+1],proD2[N+1];
pair<pair<int,int>,pair<int,int> > v1[N+1],v2[N+1];
void calc(pair<pair<int,int>,pair<int,int> > vv[]){
	vector<pair<int,int> > v(1);
	for(int i=1;i<=n;i++)v.pb(mp(a[i],i)),e[i]=a[i];
	sort(a+1,a+n+1,greater<int>());
	sort(v.begin()+1,v.end(),greater<pair<int,int> >());
	proD1[0]=proD2[0]=1;
	for(int i=1;i<=n;i++)suM1[i]=(suM1[i-1]+v[i].Y)%hmod1,proD1[i]=1ll*proD1[i-1]*v[i].Y%hmod1,suM2[i]=(suM2[i-1]+v[i].Y)%hmod2,proD2[i]=1ll*proD2[i-1]*v[i].Y%hmod2;
	v.resize(1);
	for(int i=1;i<=n;i++)v.pb(mp(b[i],i)),f[i]=b[i];
	sort(b+1,b+n+1);
	sort(v.begin()+1,v.end());
	Prod1[0]=Prod2[0]=1;
	for(int i=1;i<=n;i++)Sum1[i]=(Sum1[i-1]+v[i].Y)%hmod1,Prod1[i]=1ll*Prod1[i-1]*v[i].Y%hmod1,Sum2[i]=(Sum2[i-1]+v[i].Y)%hmod2,Prod2[i]=1ll*Prod2[i-1]*v[i].Y%hmod2;
	for(int i=1;i<=n;i++){
		int fd1=lower_bound(a+1,a+n+1,f[i],greater<int>())-a-1,fd2=lower_bound(b+1,b+n+1,e[i])-b-1;
		vv[i]=mp(mp((suM1[fd1]+Sum1[fd2])%hmod1,1ll*proD1[fd1]*Prod1[fd2]%hmod1),mp((suM2[fd1]+Sum2[fd2])%hmod2,1ll*proD2[fd1]*Prod2[fd2]%hmod2));
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i]>>d[i];
	calc(v1);
	for(int i=1;i<=n;i++)a[i]=c[i],b[i]=d[i];
	calc(v2);
	for(int i=1;i<=n;i++)if(v1[i]!=v2[i])return puts("no"),0;
	puts("yes");
	return 0;
}
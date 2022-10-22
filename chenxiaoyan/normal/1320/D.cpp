/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=200000;
int n,qu;
char a[N+5]; 
vector<int> pos;
const int hbase1=131,hmod1=998244353,hbase2=13331,hmod2=1000000007;
int Hsh1[N+1],Rhsh1[N+1],hpw1[N+1],Hsh2[N+1],Rhsh2[N+1],hpw2[N+1];
void hsh_init(){
	hpw1[0]=hpw2[0]=1;
	for(int i=1;i<=pos.size();i++)
		Hsh1[i]=(1ll*Hsh1[i-1]*hbase1+pos[i-1]%2+1)%hmod1,
		Rhsh1[i]=(1ll*Rhsh1[i-1]*hbase1+!(pos[i-1]%2)+1)%hmod1,
		hpw1[i]=1ll*hpw1[i-1]*hbase1%hmod1,
		Hsh2[i]=(1ll*Hsh2[i-1]*hbase2+pos[i-1]%2+1)%hmod2,
		Rhsh2[i]=(1ll*Rhsh2[i-1]*hbase2+!(pos[i-1]%2)+1)%hmod2,
		hpw2[i]=1ll*hpw2[i-1]*hbase2%hmod2;
}
pair<int,int> hsh(int l,int r){
	return mp(((Hsh1[r]-1ll*Hsh1[l-1]*hpw1[r-l+1]%hmod1)+hmod1)%hmod1,
			  ((Hsh2[r]-1ll*Hsh2[l-1]*hpw2[r-l+1]%hmod2)+hmod2)%hmod2);
}
pair<int,int> rhsh(int l,int r){
	return mp(((Rhsh1[r]-1ll*Rhsh1[l-1]*hpw1[r-l+1]%hmod1)+hmod1)%hmod1,
			  ((Rhsh2[r]-1ll*Rhsh2[l-1]*hpw2[r-l+1]%hmod2)+hmod2)%hmod2);
}
int main(){
	cin>>n>>a+1>>qu;
	for(int i=1;i<=n;i++)if(a[i]=='0')pos.pb(i);
	hsh_init();
	while(qu--){
		int l1,l2,len;
		scanf("%d%d%d",&l1,&l2,&len);
		int l1_0=lower_bound(pos.begin(),pos.end(),l1)-pos.begin()+1,
			r1_0=lower_bound(pos.begin(),pos.end(),l1+len)-pos.begin(),
			l2_0=lower_bound(pos.begin(),pos.end(),l2)-pos.begin()+1,
			r2_0=lower_bound(pos.begin(),pos.end(),l2+len)-pos.begin();
		pair<int,int> hsh1=l1%2?hsh(l1_0,r1_0):rhsh(l1_0,r1_0),hsh2=l2%2?hsh(l2_0,r2_0):rhsh(l2_0,r2_0);
		puts(hsh1==hsh2?"Yes":"No");
	}
	return 0;
}
/*1
10
0100001001
10
2 5 4
10 2 1
5 3 5
2 9 2
5 3 1
3 3 3
9 8 1
5 3 1
9 5 2
2 3 6
*/
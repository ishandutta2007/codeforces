/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
int n,m;
vector<pair<int,int> > ans;
void sol(int base){
	for(int i=1;i<=m/2;i*=2){
		for(int j=1;j<=m;j++)if((j+i-1)/i&1)ans.pb(mp(j+base,j+i+base));
	}
}
int main(){
	cin>>n;
	m=1<<int(log2(n));
	sol(0),sol(n-m); 
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)printf("%d %d\n",ans[i].X,ans[i].Y);
	return 0;
}
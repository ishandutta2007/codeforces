/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int N=500000,A_I=1<<20;
int n;
int a[N+1],b[N+1];
vector<pair<int,pair<int,int> > > nei[A_I];
vector<int> reg[A_I];
vector<bool> ban[A_I];
int now[A_I];// 
vector<int> pa;
void dfs(int x=a[1]){// 
//	cout<<x<<" ";
	for(int &i=now[x];i<nei[x].size();i++)if(!ban[x][i]){
		int y=nei[x][i].X,y1=nei[x][i].Y.X,y2=nei[x][i].Y.Y;
		ban[x][i]=ban[y][reg[x][i]]=true;
		dfs(y);
		pa.pb(y2);pa.pb(y1);// 
	}
}
void sol(int x){
	for(int i=1;i<=n;i++)a[i]%=1<<x,b[i]%=1<<x;
	for(int i=0;i<1<<x;i++)nei[i].clear(),reg[i].clear(),ban[i].clear();
	for(int i=1;i<=n;i++){// 
		if(a[i]==b[i]){
			nei[a[i]].pb(mp(a[i],mp(2*i-1,2*i)));nei[a[i]].pb(mp(a[i],mp(2*i,2*i-1)));
			reg[a[i]].pb(nei[a[i]].size()-1);reg[a[i]].pb(nei[a[i]].size()-2);
		}
		else{
			nei[a[i]].pb(mp(b[i],mp(2*i-1,2*i)));nei[b[i]].pb(mp(a[i],mp(2*i,2*i-1)));
			reg[a[i]].pb(nei[b[i]].size()-1);reg[b[i]].pb(nei[a[i]].size()-1);
		}
		ban[a[i]].pb(false);ban[b[i]].pb(false);
	}
	for(int i=0;i<1<<x;i++)if(nei[i].size()%2)return;// 
	memset(now,0,sizeof(now));pa.clear();
	dfs(); 
//	puts("");
	if(pa.size()!=2*n)return;// 
	cout<<x<<"\n";
	for(int i=2*n-1;~i;i--)printf("%d ",pa[i]);// 
	exit(0);
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)scanf("%d%d",a+i,b+i);
	for(int i=20;;i--)sol(i);// 
	return 0;
}
/*1
5
5 1
5 0
5 10
6 6
10 2
*/
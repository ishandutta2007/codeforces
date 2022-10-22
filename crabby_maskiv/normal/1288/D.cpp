#include<bits/stdc++.h>
#define lbt(x) (x&(-x))
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=3e5+5;
const int M=8;
const int inf=0x3f3f3f3f;
typedef pair<int,int> pii;
int n,m;
int a[N][M];
pii mx[1<<M];
int t[1<<M];
int pos[1<<M];
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>n>>m;
	for(i=0;i<m;i++) pos[1<<i]=i;
	mx[0]={inf,1};
	for(i=1;i<=n;i++){
		for(j=0;j<m;j++) cin>>a[i][j];
		t[0]=inf;
		for(j=1;j<(1<<m);j++){
			t[j]=min(t[j-lbt(j)],a[i][pos[lbt(j)]]);
			mx[j]=max(mx[j],{t[j],i});
		}
	}
	int ans=0;
	for(i=0;i<(1<<m);i++)
		ans=max(ans,min(mx[i].fr,mx[(1<<m)-1-i].fr));
//	cout<<ans<<endl;
	for(i=0;i<(1<<m);i++){
		if(min(mx[i].fr,mx[(1<<m)-1-i].fr)==ans){
			cout<<mx[i].sc<<" "<<mx[(1<<m)-1-i].sc;
			return 0;
		}
	}
	return 0;
}
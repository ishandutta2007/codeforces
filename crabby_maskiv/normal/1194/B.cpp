#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=50005; 
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
string s[N];
int x[N],y[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			s[i].clear();
			cin>>s[i];
			s[i]=" "+s[i];
		}
		for(i=1;i<=n;i++) x[i]=0;
		for(i=1;i<=m;i++) y[i]=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++)
				if(s[i][j]=='.'){
					x[i]++;
					y[j]++;
				}
		}
		int mn=inf;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				int k=x[i]+y[j]-(s[i][j]=='.');
				mn=min(mn,k);
			}
		}
		cout<<mn<<endl;
	}
	return 0;
}
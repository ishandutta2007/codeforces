#include<bits/stdc++.h>
//#define int long long
const int N=1000500;
using namespace std;

int v[N],n,m,a,b,c;

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		v[i]=0;
	for(int i=1;i<=m;i++) 
		cin>>a>>b>>c,v[b]=1;
	for(int i=1;i<=n;i++)
		if(!v[i]){
			for(int j=1;j<=n;j++)
				if(i!=j)
					cout<<i<<' '<<j<<endl;
			return ;
		}
}

int main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const ll inf=0x3f3f3f3f;
const int mod=998244353;
int n,m,k;
int a[N][N];
bool b[N][N];
int ans[N];
int main()
{
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++)
			cin>>a[i][j];
	}
	for(k=0;k<10;k++){
		bool f0=1,f1=1;
		for(i=1;i<=n;i++){
			for(j=1;j<=m;j++){
				b[i][j]=a[i][j]&(1<<k);
				if(b[i][j]) f0=0;
				else f1=0;
			}
		}
		if(f0) continue;
		if(f1&&(n%2==0)) continue;
		int p=0;
		for(i=1;i<=n;i++){
			p+=b[i][1];
			ans[i]=1;
		}
		if(p&1){
			cout<<"TAK"<<endl;
			for(i=1;i<=n;i++) cout<<1<<" ";
			return 0;
		}
		else{
			for(i=1;i<=n;i++){
				for(j=1;j<=m;j++){
					if(b[i][j]!=b[i][1]&&(p%2==0)){
						if(b[i][1]==0) p++;
						else p--;
						ans[i]=j;
						break;
					}
				}
				if(p&1) break;
			}
			if(p%2==0) continue; 
			cout<<"TAK"<<endl;
			for(i=1;i<=n;i++) cout<<ans[i]<<" ";
			return 0;
		}
	}
	cout<<"NIE";
	return 0;
}
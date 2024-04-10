#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300+5;
const int M=9e4+5;
int n,m;
int a[M],x[M];
vector<int> v[M];
int c[N][N];
int main(){
	int i,j,k;
	int _;cin>>_;
	while(_--){
		cin>>n>>m;
		for(i=1;i<=n*m;i++){
			cin>>a[i];x[i]=a[i];
			v[i].clear();
		}
		sort(x+1,x+n*m+1);
		for(i=1;i<=n*m;i++){
			a[i]=lower_bound(x+1,x+n*m+1,a[i])-x;
			v[a[i]].push_back(i);
		}
		int cnt=0;
		for(k=1;k<=n*m;k++){
			if(v[k].empty()) continue;
			sort(v[k].begin(),v[k].end(),greater<int>());
			int r1=cnt/m+1,c1=cnt%m+1;
			cnt+=v[k].size();
			int r2=(cnt-1)/m+1,c2=(cnt-1)%m+1;
			if(r1==r2){
				for(i=0;i<v[k].size();i++)
					c[r1][c1+i]=v[k][i];
			}
			else{
				for(i=0;i<c2;i++)
					c[r2][i+1]=v[k][i];
				for(r2--;r2>r1;r2--){
					j=i;
					for(;i<j+m;i++) c[r2][i-j+1]=v[k][i];
				}
				j=i;
				for(;i<v[k].size();i++)
					c[r1][c1+i-j]=v[k][i];
			}
		}
		int ans=0;
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				for(k=1;k<j;k++) ans+=(c[i][k]<c[i][j]);
	//	cout<<"answ = "<<ans<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=55;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
int a[N][N],b[N][N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++) 
			cin>>a[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++) 
			cin>>b[i][j];
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]>b[i][j])
				swap(a[i][j],b[i][j]);
		}
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if(a[i][j]<=a[i-1][j]||a[i][j]<=a[i][j-1]){
				cout<<"Impossible";
				return 0;
			}
			if(b[i][j]<=b[i-1][j]||b[i][j]<=b[i][j-1]){
				cout<<"Impossible";
				return 0;
			}
		}
	cout<<"Possible";
	return 0;
}
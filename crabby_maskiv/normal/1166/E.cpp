#include<bits/stdc++.h>
#define lbt(x) (x&(-x))
using namespace std;
typedef long long ll;
const int N=10005;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m; 
int a[N];
bool b[55][N];
int main(){
	ios::sync_with_stdio(0);
    int i,j;
	cin>>m>>n;
	for(i=1;i<=m;i++){
		int t;
		cin>>t;
		while(t--){
			int x;cin>>x;
			b[i][x]=1;
		}
	}
	for(i=1;i<=m;i++){
		for(j=i+1;j<=m;j++){
			bool flag=0;
			for(int k=1;k<=n;k++){
				if(b[i][k]&&b[j][k])
					flag=1;
			}
			if(!flag){
				cout<<"impossible";
				return 0;
			}
		}
	}
	cout<<"possible";
    return 0;
}
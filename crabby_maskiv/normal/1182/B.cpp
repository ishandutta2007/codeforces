#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const ll inf=0x3f3f3f3f;
const ll mod=998244353;
int n,m;
int cnt;
char a[N][N];
bool check(int x,int y){
	if(x==1||x==n||y==1||y==m) return 0;
	int i,j;
	int tmp=1;
	if(a[x][y-1]=='.'||a[x-1][y]=='.'||a[x][y+1]=='.'||a[x+1][y]=='.') return 0;
	if(a[x][y]!='*') return 0;
	for(i=x-1;a[i][y]=='*';i--) tmp++;
	for(i=x+1;a[i][y]=='*';i++) tmp++;
	for(i=y-1;a[x][i]=='*';i--) tmp++;
	for(i=y+1;a[x][i]=='*';i++) tmp++;
	return tmp==cnt;
}
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>a[i][j];
			cnt+=(a[i][j]=='*');
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			if(a[i][j]=='*'){
				if(check(i,j)){
					cout<<"YES";
					return 0;
				}
			}
		}
	}
	cout<<"NO";
	return 0;
}
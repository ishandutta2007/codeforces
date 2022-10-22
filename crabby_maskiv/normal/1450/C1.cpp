#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=300+5;
int n,m;
char a[N][N];
int c[3][2];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>(a[i]+1);
		memset(c,0,sizeof(c));
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(a[i][j]=='O') c[(i+j-2)%3][0]++;
				else if(a[i][j]=='X') c[(i+j-2)%3][1]++;
			}
		}
		int cnt=0,p1=0,p2=1;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(i==j) continue;
				if(c[i][0]+c[j][1]<c[p1][0]+c[p2][1]){
					p1=i;p2=j;
				}
			}
		}
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if((i+j-2)%3==p1&&a[i][j]=='O'){
					cnt++;
					a[i][j]='X';
				}
				if((i+j-2)%3==p2&&a[i][j]=='X'){
					cnt++;
					a[i][j]='O';
				}
			}
		}
		cerr<<cnt<<endl;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++) cout<<a[i][j];
			cout<<endl;
		}
	}
	return 0;
}
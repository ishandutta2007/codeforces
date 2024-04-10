#include <bits/stdc++.h>
using namespace std;

int a[3],b[3];
char c[310][310];

signed main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;cin>>n;
		int k=0;
		for(int i=0;i<3;i++) a[i]=b[i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cin>>c[i][j];
				if(c[i][j]=='X') a[(i+j)%3]++,k++;
				else if(c[i][j]=='O') b[(i+j)%3]++,k++;
			}
		}
		bool ok=false;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(i!=j&&a[i]+b[j]<=k/3&&!ok){
					ok=true;
					for(int ii=1;ii<=n;ii++){
						for(int jj=1;jj<=n;jj++){
							if(c[ii][jj]=='.') cout<<'.';
							else if(c[ii][jj]=='X'){
								if((ii+jj)%3==i) cout<<'O';
								else cout<<'X';
							}
							else{
								if((ii+jj)%3==j) cout<<'X';
								else cout<<'O';
							}
						}
						cout<<'\n';
					}
				}
			}
		}
	}
	return 0;
}
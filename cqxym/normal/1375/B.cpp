#include<iostream>
using namespace std;
#define R register int
const int DIR[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int a[300][300];
inline void Solve(){
	int n,m;
	cin>>n>>m;
	for(R i=0;i!=n;i++){
		for(R j=0;j!=m;j++){
			cin>>a[i][j];
		}
	}
	for(R i=0;i!=n;i++){
		for(R j=0;j!=m;j++){
			int ct=0;
			for(R k=0;k!=4;k++){
				int x=i+DIR[k][0],y=j+DIR[k][1];
				if(x!=-1&&y!=-1&&x!=n&&y!=m){
					ct++;
				}
			}
			if(ct<a[i][j]){
				cout<<"NO\n";
				return;
			}
			a[i][j]=ct;
		}
	}
	cout<<"YES\n";
	for(R i=0;i!=n;i++){
		for(R j=0;j!=m;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}
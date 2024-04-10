#include<bits/stdc++.h>
//#define int long long
const int N=500005;
using namespace std;

int a[5][N],n;

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=0;j<5;j++)
			cin>>a[j][i];
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			if(i!=j){
				int c1=0,c2=0,c3=0;
				for(int k=1;k<=n;k++)
					if(a[i][k]&&a[j][k])
						c3++;
					else if(a[i][k])c1++;
					else if(a[j][k])c2++;
				if(c1+c2+c3==n&&max(c1,c2)<=n/2){
					cout<<"YES"<<endl;
					return;
				}
			}
	cout<<"NO"<<endl;
	return;
} 

int main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;while(t--)solve();
}
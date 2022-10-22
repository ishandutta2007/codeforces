/*








 l l
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int n;
int a[N+1][N+1];
int main(){
	cin>>n;
	int now=0;
	for(int i=1;i<=n/2;i++)for(int j=1;j<=n/2;j++)a[i][j]=now++<<2;
	for(int i=n/2+1;i<=n;i++)for(int j=1;j<=n/2;j++)a[i][j]=a[i-n/2][j]+1;
	for(int i=1;i<=n/2;i++)for(int j=n/2+1;j<=n;j++)a[i][j]=a[i][j-n/2]+2;
	for(int i=n/2+1;i<=n;i++)for(int j=n/2+1;j<=n;j++)a[i][j]=a[i-n/2][j-n/2]+3;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)cout<<a[i][j]<<" ";
		puts("");
	}
//	for(int i=1;i<=n;i++){
//		int sum=0;
//		for(int j=1;j<=n;j++)sum^=a[i][j];
//		cout<<sum<<"\n";
//	}
	return 0;
}
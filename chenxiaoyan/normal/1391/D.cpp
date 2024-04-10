/*





D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1000000;
int n,m;
vector<string> v;
bool a[4][N+1];
int main(){
	cin>>n>>m;
	if(n>=4&&m>=4)return puts("-1"),0;
	for(int i=1;i<=n;i++){
		string a;
		cin>>a;
		v.pb(a);
	}
	if(n>=4){
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[j][i]=v[i-1][j-1]^48;
		swap(n,m);
	}
	else{
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i][j]=v[i-1][j-1]^48;
	}
//	for(int i=1;i<=n;i++){for(int j=1;j<=m;j++)cout<<a[i][j];puts("");}
	if(n==1)puts("0");
	else if(n==2){
		int ans=0;
		for(int i=1;i<=m;i++)ans+=(a[1][i]^a[2][i])==(i&1);
		cout<<min(ans,m-ans);
	}
	else{
		int ans1=0,ans2=0,ans3=0,ans4=0;
		for(int i=1;i<=m;i++)ans1+=(a[1][i]^a[2][i])!=(i&1)||(a[2][i]^a[3][i])!=(i&1);
		for(int i=1;i<=m;i++)ans2+=(a[1][i]^a[2][i])==(i&1)||(a[2][i]^a[3][i])!=(i&1);
		for(int i=1;i<=m;i++)ans3+=(a[1][i]^a[2][i])!=(i&1)||(a[2][i]^a[3][i])==(i&1);
		for(int i=1;i<=m;i++)ans4+=(a[1][i]^a[2][i])==(i&1)||(a[2][i]^a[3][i])==(i&1);
		cout<<min(min(ans1,ans2),min(ans3,ans4));
	}
	return 0;
}
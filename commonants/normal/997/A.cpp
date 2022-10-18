#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MX=300005;
int n,x,y;
char s[MX],t[MX];
int c=0;
ll f[MX][2];

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>x>>y;
	cin>>s;
	char lst=-1;
	for(int i=0;i<n;i++)if(lst!=s[i])t[c++]=lst=s[i];
	n=c;
	for(int i=1;i<=n;i++){
		for(int j=1;j>=0;j--){
			if(i!=1||j!=1)f[i][j]=1ll<<60;else f[i][j]=0;
			if(!j)f[i][j]=min(f[i][j],f[i][j^1]+y);
			if(i>1)f[i][j]=min(f[i][j],f[i-1][j^1]+y);
			if(i>1)f[i][j]=min(f[i][j],f[i-1][j]+y);
			if(i>2)f[i][j]=min(f[i][j],f[i-1][j^1]+x);
			if(i>2)f[i][j]=min(f[i][j],f[i-1][j]+x);
			if(i>2)f[i][j]=min(f[i][j],f[i-2][j]+y);
			if(i>3)f[i][j]=min(f[i][j],f[i-2][j]+x);
			// cerr<<i<<' '<<j<<' '<<f[i][j]<<endl;
		}
	}
	cout<<f[n][t[0]-'0']<<endl;
	return 0;
}
// r-l=max-min

// f[i][j]: i  j 
// f[i][j](...)
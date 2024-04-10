#include<bits/stdc++.h>
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+5;
const int inf=0x3f3f3f3f;
int n,m;
inline int calc(int a,int b,int c,int d){
	if(b==c) return b+c;
	return inf;
}
char a[N],b[N];
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		cin>>(a+1)>>(b+1);
		int c00=0,c11=0,c01=0,c10=0;
		for(i=1;i<=n;i++){
			c00+=(a[i]=='0'&&b[i]=='0');
			c01+=(a[i]=='0'&&b[i]=='1');
			c10+=(a[i]=='1'&&b[i]=='0');
			c11+=(a[i]=='1'&&b[i]=='1');
		}
		int ans=calc(c00,c01,c10,c11);
		if(c10) ans=min(ans,calc(c10-1,c11,c00+1,c01)+1);
		if(c11) ans=min(ans,calc(c10,c11-1,c00,c01+1)+1);
		if(ans==inf) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	return 0;
}
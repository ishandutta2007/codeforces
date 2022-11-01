/******************
*  Writer: BD747  *
******************/
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

typedef long long LL;

LL n;
LL a[200005];
LL x,f;
LL ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>x>>f;
	
	for(int i=1;i<=n;i++){
		if( (a[i]-x+x+f-1) / (x+f) > 0 ){
			ans+= (a[i]-x+x+f-1) / (x+f) ;
		}
	}
	
	cout<<ans*f<<endl;
	
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	int x,y,z,a=0,b=0,c=0,m,n,i,j,k;
	cin>>m;
	while(m--){
		cin>>x>>y>>z;
		a+=x,b+=y,c+=z;
	}
	if(a==0&&b==0&&c==0) cout<<"YES"<<endl;
	else puts("NO");

  return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
int i,j,k,m,T;
long long n;
int main(){;
	cin>>T;
	while(T--){
		cin>>n;
		n=(n+1)/2;
		if(n<=3)cout<<15<<endl;
		else cout<<n*5<<endl;
	}
	return 0;
}
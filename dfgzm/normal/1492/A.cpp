#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T;
ll p,a,b,c;
int main(){
	cin>>T;
	while(T--){
		cin>>p>>a>>b>>c;
		if(p%a==0 || p%b==0 || p%c==0)cout<<0<<endl;
		else cout<<min(a-p%a,min(b-p%b,c-p%c))<<endl;
	}
	return 0;
}
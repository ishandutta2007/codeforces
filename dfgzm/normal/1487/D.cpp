#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
ll i,j,k,n,m,T;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		ll L=1,R=n;
		while(L<=R){
			ll Mid=L+R>>1;
			if((Mid*Mid)/2+1<=n)L=Mid+1;
			else R=Mid-1;
		}cout<<L/2-1<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int i,j,k,n,m,T,a,b;
int check(int a,int b){
	if(!a)return 0;
	return check(a/b,b)+1;
}
int main(){
	cin>>T;
	while(T--){
		cin>>a>>b;
		if(b>sqrt(a)){
			cout<<check(a,b)<<endl;
		}else{
			int ans=1e9;
			for(int i=max(2,b);i<=sqrt(a)+1;i++){
				ans=min(ans,check(a,i)+i-b);
			}cout<<ans<<endl;
		}
	}
	return 0;
}
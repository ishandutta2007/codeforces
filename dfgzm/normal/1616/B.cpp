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
string S;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cin>>S;
		bool is=0;
		for(i=1;i<n;i++){
			if(S[i]!=S[0])is=1;
			if(S[i]>S[i-1])break;
			if(S[i]==S[i-1] && !is)break;
		}
		for(j=1;j<=i;j++)putchar(S[j-1]);
		for(j=i;j>=1;j--)putchar(S[j-1]);
		puts("");
	}
	return 0;
}
#include <bits/stdc++.h>
#define ll long long
#define Mid ((L+R)>>1)
using namespace std;
typedef pair<int,int> pii;
inline int read(){
	char c;int x=0;int b=1;do{c=getchar();if(c==45)b=-1;}while(c>57||c<48);
	do x=x*10+c-48,c=getchar();while(c<=57&&c>=48);x*=b;return x;
}
int i,j,k,n,m;
string S;
int main() {
	int T=read();
	while(T--){
		n=read();m=read();
		cin>>S;bool B=false;
		for(i=0;i+m<n;i++){
			if(S[i+m]=='?')S[i+m]=S[i];
			if(S[i]+S[i+m]=='1'+'0')B=true;
		}
		int one=0,zero=0;
		for(i=n-1;i+m>=n;i--)one+=S[i]=='1',zero+=S[i]=='0';
		B|=(one>m/2)|(zero>m/2);
		puts(B?"NO":"YES");
	}
	//cerr << 1.0*clock()/CLOCKS_PER_SEC << endl;
	return 0;
}
#include<bits/stdc++.h>
#define LL long long
#define mp make_pair
#define fi first
#define se second
using namespace std;
int read(){
	char ch=getchar(); int x=0,fl=1;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') fl=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch-'0');
	return x*fl;
}

int main(){
	int T=read();
	while(T--){
		LL n=read(),a=read(),b=read();
		LL t=1,tim=0;
		bool fl=0;
		while(t<=n){
			if(n%b==t%b){
				cout<<"Yes\n";
				fl=1;
				break;
			}
			t*=a;
			tim++;
			if(tim>100){
				break;
			}
		}
		if(!fl) cout<<"No\n";
	}
	return 0;
}
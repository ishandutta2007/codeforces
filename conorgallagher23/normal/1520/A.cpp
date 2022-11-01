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

int n;
char s[55];
map<char,bool> fl;
void solve(){
	fl.clear();
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		if(i==1||s[i]!=s[i-1]){
			if(fl[s[i]]){
				cout<<"NO\n";
				return;
			}
			fl[s[i]]=1;
		}
	}
	cout<<"YES\n";
}

int main(){
	int T=read();
	while(T--) solve();
	return 0;
}
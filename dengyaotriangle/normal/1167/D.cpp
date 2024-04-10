#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

int n;
char s[maxn];
bool bl[maxn];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	cin>>(s+1);
	int cdp=0,mdp=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='(') cdp++;
		else cdp--;
		mdp=max(mdp,cdp);
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='(') cdp++;
		if(cdp>mdp/2){
			bl[i]=0;
		}else bl[i]=1;
		if(s[i]==')') cdp--;
	}
	for(int i=1;i<=n;i++)cout<<(int)bl[i];
	return 0;
}
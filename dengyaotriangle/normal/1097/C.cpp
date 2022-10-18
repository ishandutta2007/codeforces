#include<bits/stdc++.h>

using namespace std;

const int maxn=500005;

char x[maxn];
int n,l;
int vlu[maxn],vlc;
int cnt[maxn],cnf[maxn],ctm;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		l=0;while(x[l])l++;
		int cr=0,mn=0,mx=0;
		for(int j=0;j<l;j++){
			if(x[j]=='(') cr++;
			if(x[j]==')') cr--;
			if(cr<0){
				cr++;
				mn--;
			}
		}
		cr=0;
		for(int j=l-1;j>=0;j--){
			if(x[j]=='(') cr--;
			if(x[j]==')') cr++;
			if(cr<0){
				cr++;
				mx++;
			}
		}
		if(mx==0) vlu[++vlc]=mn;
		else if(mn==0) vlu[++vlc]=mx;
	}
	for(int i=1;i<=vlc;i++){
		if(vlu[i]==0) ctm++;
		else if(vlu[i]>0) cnt[vlu[i]]++;
		else cnf[0-vlu[i]]++;
	}
	int ans=ctm/2;
	for(int i=1;i<maxn;i++){
		ans+=min(cnt[i],cnf[i]);
	}
	cout<<ans;
	return 0;
}
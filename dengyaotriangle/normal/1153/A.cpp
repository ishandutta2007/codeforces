#include <bits/stdc++.h>
using namespace std;
//lmy ak ioi
const int maxn=105;

int n,p;

int s[maxn],t[maxn];

int main(){
	cin>>n>>p;
	for(int i=1;i<=n;i++)cin>>s[i]>>t[i];
	int minn=0x3fff3fff,mini=0;
	for(int i=1;i<=n;i++){
		int cur=s[i];
		while(cur<p){
			cur+=t[i];
		}
		int ps=cur-p;
		if(ps<minn){
			minn=ps;
			mini=i;
		}
	}
	cout<<mini;
	return 0;
}
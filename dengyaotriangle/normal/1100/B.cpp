#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int oc[maxn];
int n,m;
int vlc[maxn],cp;

int main(){
	cin>>n>>m;
	vlc[0]=n;
	for(int i=1;i<=m;i++){
		int t;
		cin>>t;
		vlc[oc[t]]--;
		oc[t]++;
		vlc[oc[t]]++;
		if(vlc[cp]==0){
			cout<<'1';
			cp++;
		}else cout<<'0';
	}
	
	return 0;
}
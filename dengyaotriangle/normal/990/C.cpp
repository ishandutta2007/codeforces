#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

int n;
int d[maxn],v[maxn],fd[maxn],w[maxn];
char tmp[maxn];
long long hs[maxn+maxn+maxn];
bool mk[maxn];
long long ans=0;
int l=0;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		int tl=0;
		v[i]=maxn;
		w[i]=0-maxn;
		while(tmp[tl++]){
			if(tmp[tl-1]=='(') d[i]++;
			if(tmp[tl-1]==')') d[i]--;
			v[i]=min(v[i],d[i]);
		}
		for(int j=tl-1;j>=0;j--){
			if(tmp[tl-1]=='(') d[j]++;
			if(tmp[tl-1]==')') d[j]--;
			w[j]=max(w[i],d[j]);
		}
		if((v[i]<0&&v[i]!=d[i])||(w[i]>0&&w[i]!=d[i])) continue;
		hs[d[i]+maxn]++;
		fd[l++]=d[i];
	}
	for(int i=0-maxn;i<=0;i++){
		ans+=hs[i+maxn]*hs[0-i+maxn];
	}
	cout<<ans;
	return 0;
}
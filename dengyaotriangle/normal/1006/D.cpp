#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
char a[maxn],b[maxn];
long long ans=0;

int dif(char a,char b){
	if(a!=b) return 1;
	return 0;
}

int main(){
	cin>>n>>a>>b;
	for(int i=0;i<n/2;i++){
		int fa=i,fb=n-i-1;
		int an=100;
		if(b[fa]==b[fb]) an=dif(a[fa],a[fb]);
		an=min(an,min(dif(a[fa],b[fa])+dif(a[fb],b[fb]),dif(a[fa],b[fb])+dif(a[fb],b[fa])));
		ans+=an;
	}
	if(n%2==1){
		if(a[n/2]!=b[n/2]) ans++;
	}
	cout<<ans;
	return 0;
}
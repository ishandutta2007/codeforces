#include<bits/stdc++.h>

using namespace std;

const int maxn=1005;

int n,m,q;
char a[maxn],b[maxn];
int oc[maxn];

int main(){
	cin>>n>>m>>q;
	cin>>a>>b;
	for(int i=0;i<n-m+1;i++){
		bool ok=1;
		for(int j=i;j<i+m;j++){
			if(a[j]!=b[j-i]) ok=0;
		}
		if(ok ) oc[i]=1;
		else oc[i]=0;
		//cout<<oc[i];
	}
	for(int i=0;i<q;i++){
		int l,r;
		cin>>l>>r;
		l--;r--;
		int co=0;
		for(int j=l;j<=r-m+1;j++){
			co+=oc[j];
		}
		cout<<co<<endl;
	}
	return 0;
}
#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n;
int a[maxn];
int ct[maxn];
int at[maxn];
int b[maxn];
int bt[maxn];
int cl[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ct[a[i]]++;
	}
	for(int i=0;i<n;i++){
		if((ct[i]%(n-i))){
			cout<<"Impossible";
			return 0;
		}
		bt[i]=ct[i];
	}
	cout<<"Possible"<<endl;
	for(int i=0;i<n;i++) cl[i]=-1;
	int tcl=0;
	for(int i=1;i<=n;i++){
		if(cl[a[i]]==-1) cl[a[i]]=++tcl;
		b[i]=cl[a[i]];
		bt[a[i]]--;
		if(0==(bt[a[i]]%(n-a[i]))&&bt[a[i]]>0) cl[a[i]]=++tcl;
	}
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	return 0;
}
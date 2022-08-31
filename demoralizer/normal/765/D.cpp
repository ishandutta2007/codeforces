#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
int main(){
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin>>n;
	int f[n+1];
	set<int> a,b;
	for(int i=1;i<=n;i++){
		cin>>f[i];
		a.insert(f[i]);
		if(i==f[i])b.insert(f[i]);
	}
	if(a.size()!=b.size()){
		cout<<"-1";
		return 0;
	}
	int m=a.size(),j=1,h[m+1];
	map<int,int> z;
	set<int>::iterator i=a.begin();
	for(;i!=a.end();i++){
		h[j]=*i;
		z[h[j]]=j;
		j++;
	}
	cout<<m<<"\n";
	for(int i=1;i<=n;i++){
		cout<<z[f[i]]<<" ";
	}
	cout<<"\n";
	for(int i=1;i<=m;i++){
		cout<<h[i]<<" ";
	}
}
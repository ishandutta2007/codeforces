#include<bits/stdc++.h>
const int N=2005000;
using namespace std;

vector<int> KMP(string&b){
	vector<int> fa(b.size()+1);
	for(int i=2,j=0;i<b.size();i++){
		while(j&&b[i]!=b[j+1])j=fa[j];
		if(b[i]==b[j+1])j++;
		fa[i]=j;
	}
	return fa;
}

int n,k,ans[N];
string s;

int main(){
	cin>>n>>k>>s;s=' '+s;
	auto fa=KMP(s);
//	for(auto x:fa)cout<<x<<' ';cout<<endl;
	for(int i=1;i<=n;i++){
		int x=i-fa[i],d=i/x;
		if(i%x)ans[i]=d/k-d%k>0;
		else ans[i]=d/k-d%k>=0;
	}
	for(int i=1;i<=n;i++)
		cout<<ans[i];cout<<endl;
}
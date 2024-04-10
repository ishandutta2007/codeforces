#include<bits/stdc++.h>
using namespace std;
int n,a[2040];
vector<int>res;
int find(int x){
	for(int i=1;i<=n;i++)if(a[i]==x)return i;
}
void add(int x){
	res.push_back(x);
	for(int i=1,j=x;i<j;i++,j--)swap(a[i],a[j]);
}
void solve(){
	res.clear();
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		if(i%2!=a[i]%2){
			puts("-1");
			return;
		}
	for(int i=n;i>1;i-=2){
		int posA=find(i);
		add(posA);
		int posB=find(i-1);
		add(posB-1);
		add(posB+1);
		add(3);
		add(i);
	}
	cout<<res.size()<<"\n";
	for(auto x:res)cout<<x<<" ";puts(""); 
}
int main(){
	int Tc;
	for(cin>>Tc;Tc--;solve());
}
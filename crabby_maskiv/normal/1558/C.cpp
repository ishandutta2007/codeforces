#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e3+5;
int n,m;
int a[N];
vector<int> ans;
inline void flip(int x){
	ans.push_back(x);
	for(int i=1;i<x-i+1;i++) swap(a[i],a[x-i+1]);
}
int main(){
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		int f=0;
		for(i=1;i<=n;i++)
			f|=((a[i]&1)^(i&1));
		if(f==1){
			cout<<-1<<endl;
			continue;
		}
		ans.clear();
		for(i=n;i>1;i-=2){
			int p1,p2;
			for(j=1;j<=n;j++){
				if(a[j]==i-1) p1=j;
				if(a[j]==i) p2=j;
			}
			if(p1<p2){
				flip(p2);
				flip(p2-p1);
				flip(i);
				flip(i-p2+p1+1);
				flip(i);
			}
			else{
				flip(p2);
				flip(p1-1);
				flip(i);
				flip(i-p1+2);
				flip(i);
			}
		}
		cout<<ans.size()<<endl;
		for(auto x:ans) cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
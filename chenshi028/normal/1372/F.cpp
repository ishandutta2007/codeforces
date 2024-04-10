#include<iostream>
#include<map>
using namespace std;
const int o=2e5+10;
int n,ans[o];
map<int,int> mp;
int calc(int l,int r){
	if(l>r) return l-1;
	cout<<"? "<<l<<" "<<r<<endl;cout.flush();
	int x,f;cin>>x>>f;
	if(mp[x]){
		int ed=r-f+mp[x];
		for(int i=ed-mp[x]+1;i<=ed;++i) ans[i]=x;
		mp[x]=0;calc(l,r-f);
		return ed;
	}
	mp[x]=f;int i=l;
	while(mp[x]) i=calc(i,i+f-1)+1;
	return calc(i,r); 
}
int main(){
	cin>>n;
	calc(1,n);
	cout<<"!";for(int i=1;i<=n;++i) cout<<" "<<ans[i];cout.flush();
	return 0;
}
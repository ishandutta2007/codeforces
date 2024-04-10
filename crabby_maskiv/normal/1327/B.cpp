#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
int n,m;
set<int> s;
bool vis1[N],vis2[N];
int tmp[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		s.clear();
		for(i=1;i<=n;i++){
			s.insert(i);
			vis1[i]=vis2[i]=0;
		}
		for(i=1;i<=n;i++){
			cin>>m;
			for(j=1;j<=m;j++) cin>>tmp[j];
			for(j=1;j<=m;j++){
				if(s.find(tmp[j])!=s.end()){
					vis1[tmp[j]]=vis2[i]=1;
					s.erase(tmp[j]);
					break;
				}
			}
		}
		int cnt=0;
		for(i=1;i<=n;i++)
			cnt+=(!vis1[i]);
		if(!cnt) cout<<"OPTIMAL"<<endl;
		else{
			cout<<"IMPROVE"<<endl;
			for(i=1;i<=n;i++){
				if(!vis2[i]){
					cout<<i<<" ";
					break;
				}
			}
			for(i=1;i<=n;i++){
				if(!vis1[i]){
					cout<<i<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
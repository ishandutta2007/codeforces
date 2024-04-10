#include <bits/stdc++.h>
using namespace std;
int T,n,num[11]={2,3,5,7,11,13,17,19,23,29,31},res[1003];
vector<int>ans[11];
int main(){
	cin>>T;
	while (T--){
		cin>>n;
		for (int i=0;i<11;i++) ans[i].clear();
		for (int i=1;i<=n;i++){
			int x;cin>>x;
			for (int j=0;j<11;j++) if (x%num[j]==0){
				ans[j].push_back(i);
				break;
			}
		}
		int cnt=0;
		for (int i=0;i<11;i++) if (ans[i].size()>0){
			cnt++;
			for (int j=0;j<ans[i].size();j++) res[ans[i][j]]=cnt;
		}
		cout<<cnt<<"\n";
		for (int i=1;i<=n;i++) cout<<res[i]<<" ";
		puts("");
	}
}
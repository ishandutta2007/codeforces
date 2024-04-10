#include<bits/stdc++.h>
using namespace std;
const int N=100+10;
vector<int>path;
bool qry1(int x,int y){
	cout<<1<<' '<<x<<' '<<y<<endl;
	int res;cin>>res;return res;
}
bool qry2(int x,int len){
	if(len<0)return false;
	cout<<2<<' '<<x<<' '<<len+1<<' ';
	for(int i=0;i<=len;i++)cout<<path[i]<<' ';cout<<endl;
	int res;cin>>res;return res;
}
bool ans[N][N];
signed main(){
	ios::sync_with_stdio(false);
	int t;cin>>t;
	while(t--){
		memset(ans,1,sizeof ans);
		int n;cin>>n;
		path.clear();for(int i=1;i<=n;i++)path.push_back(i-1);
		stable_sort(path.begin(),path.end(),qry1);
		//for(auto x:path)printf("%d ",x);puts("");
		for(int r=n-1,l=n-2;r>=0;r--){
			if(l==r){
				for(int j=0;j<=r;j++)
					for(int k=r+1;k<n;k++)
						ans[path[k]][path[j]]=false;
				l--;
			}
			while(qry2(path[r],l))l--;
		}
		cout<<3<<"\n";
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++)
				cout<<ans[i][j];
			cout<<endl;
		}
		cin>>n;
	}
}
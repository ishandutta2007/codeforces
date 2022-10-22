#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> v;
bool vis[200];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		int N;
		cin>>N;
		for(int i=0;i<N;i++){
			int a;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		int tot=0;
		for(int i=0;i<v.size();i++){
			if(vis[i])continue;
			vis[i]=1;
			tot++;
			for(int j=i+1;j<v.size();j++){
				if(v[j]%v[i]==0)vis[j]=1;
			}
		}
		cout<<tot;
		return 0;
}
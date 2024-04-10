#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e3+5;
int n,m;
int a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j;
	int _;cin>>_;
	while(_--){
		cin>>n;
		for(i=1;i<=n;i++) cin>>a[i];
		vector<int> v;
		for(i=1;i<=n;i++){
			if(a[i]==1) v.push_back(1);
			else{
				while(v.size()){
					if(v.back()==a[i]-1){
						v.pop_back();
						v.push_back(a[i]);
						break;
					}
					else v.pop_back();
				}
			}
			for(j=0;j<v.size()-1;j++) cout<<v[j]<<".";
			cout<<v.back()<<endl;
		}
	}
	return 0;
}
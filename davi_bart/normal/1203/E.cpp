#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> p;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N;
		cin>>N;
		for(int i=0;i<N;i++){
			int a;
			cin>>a;
			p.push_back(a);
		}
		sort(p.begin(),p.end());
		int tot=0;
		int k=1;
		for(int i=0;i<p.size();i++){
			if(abs(p[i]-k)<=1){
				k++;
				tot++;
			}else{
				if(p[i]>k){
					tot++;
					k=p[i];
				}
			}
		}
		cout<<tot;
		return 0;
}
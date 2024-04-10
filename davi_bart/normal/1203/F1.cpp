#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<int,int> > sale,scende;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N,K;
		cin>>N>>K;
		for(int i=0;i<N;i++){
			int a,b;
			cin>>a>>b;
			if(b>=0)sale.push_back({a,b});
			else scende.push_back({a,b});
		}
		sort(sale.begin(),sale.end());
		for(int i=0;i<sale.size();i++){
			if(sale[i].first>K){
				cout<<"NO";
				return 0;
			}
			K+=sale[i].second;
		}
		if(scende.size()==0){
		    cout<<"YES";
		    return 0;
		}
		sort(scende.begin(),scende.end(),greater<pair<int,int> >());
		for(int i=0;i<500000;i++){
			int l=K;
			for(int j=0;j<scende.size();j++){
				if(l<scende[j].first)break;
				l+=scende[j].second;
				if(j==scende.size()-1 && l>=0){
					cout<<"YES";
					return 0;
				}
			}
			random_shuffle(scende.begin(),scende.end());
		}
		cout<<"NO";
		return 0;
}
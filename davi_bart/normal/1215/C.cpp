#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> tipo1,tipo2;
vector<pair<int,int> > sol;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		int N;
		cin>>N;
		string a,b;
		cin>>a>>b;
		int a1=0,a2=0;
		for(int i=0;i<N;i++){
			if(a[i]=='a')a1++;
			if(b[i]=='a')a2++;
			if(a[i]!=b[i]){
				if(a[i]=='a')tipo1.push_back(i+1);
				else tipo2.push_back(i+1);
			}
		}
		if(abs(a1-a2)%2){
			cout<<-1;
			return 0;
		}
		if(tipo1.size()%2){
      tipo2.push_back(tipo1.back());
      tipo1.erase(tipo1.begin()+tipo1.size()-1);
      sol.push_back({tipo2.back(),tipo2.back()});
		}
		int n=tipo1.size()/2;
		for(int i=0;i<n;i++){
			sol.push_back({tipo1[i],tipo1[i+n]});
		}
		n=tipo2.size()/2;
		for(int i=0;i<n;i++){
			sol.push_back({tipo2[i],tipo2[i+n]});
		}
		cout<<sol.size()<<endl;
		for(int i=0;i<sol.size();i++){
			cout<<sol[i].first<<" "<<sol[i].second<<endl;
		}
		return 0;
}
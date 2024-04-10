#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string a,b;
vector<int>ini,fin;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		cin>>a>>b;
		int pos=0;
		ini.push_back(-1);
		fin.push_back(a.size());
		for(int i=0;i<a.size();i++){
			if(a[i]==b[pos]){
				ini.push_back(i);
				pos++;
			}
			if(pos==b.size())break;
		}
		pos=b.size()-1;
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]==b[pos]){
				fin.push_back(i);
				pos--;
			}
			if(pos<0)break;
		}
		int sol=0;
		for(int i=0;i<ini.size();i++){
			sol=max(sol,fin[b.size()-i]-ini[i]-1);
		}
		cout<<sol;
		return 0;
}
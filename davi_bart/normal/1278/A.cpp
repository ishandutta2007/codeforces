#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
			string a,b;
			cin>>a>>b;
			if(a.size()>b.size()){
        cout<<"NO"<<endl;
        continue;
			}
			vector<int> v(3000,0);
			for(int i=0;i<a.size();i++)v[a[i]]++;
			for(int i=0;i<a.size();i++)v[b[i]]--;
			bool k=0;
			for(int i=a.size();i<b.size();i++){
				bool p=0;
				for(int j=0;j<290;j++){
					if(v[j]!=0){
						p=1;
						break;
					}
				}
				if(p==0){
					cout<<"YES"<<'\n';
					k=1;
					break;
				}
				v[b[i-a.size()]]++;
				v[b[i]]--;
			}
			if(k)continue;
			bool p=0;
      for(int j=0;j<290;j++){
        if(v[j]!=0){
          p=1;
          break;
        }
      }
      if(p==0){
        cout<<"YES"<<'\n';
        continue;
      }
			cout<<"NO"<<'\n';
		}
    return 0;
}
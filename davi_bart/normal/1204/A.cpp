#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		string a;
		cin>>a;
		int sol=a.size()/2;
		for(int i=1;i<a.size();i++){
      if(a.size()%2 && a[i]=='1'){
        sol++;
        break;
      }
		}
		cout<<sol<<endl;
		return 0;
}
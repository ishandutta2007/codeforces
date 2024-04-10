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
		int m=0;
		for(int i=a.size()-1;i>=0;i--){
			if(a[i]=='1')m++;
			else m--;
			if(m>0){
          a[i]='0';
          m=0;
			}
		}
		cout<<a;
		return 0;
}
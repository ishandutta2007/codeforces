#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
			int a,b,c;
			cin>>a>>b>>c;
			a/=2;
			int d,e;
			cin>>d>>e;
			if(d>e){
				cout<<d*(min(a,b))+e*min(c,max(0,a-b))<<endl;
			}else{
				cout<<e*(min(a,c))+d*min(b,max(0,a-c))<<endl;
			}
		}
		return 0;
}
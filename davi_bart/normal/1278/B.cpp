#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int T;
		cin>>T;
		while(T--){
			int a,b;
			cin>>a>>b;
			b=abs(a-b);
			int tot=0;
			if(b==0){
        cout<<0<<endl;
        continue;
			}
      a=0;
			for(int i=1;i<1000000000;i++){
        a+=i;
        tot++;
        if(a>=b && ((a-b)/2)*2+b==a)break;
			}
			cout<<tot<<'\n';
		}
    return 0;
}
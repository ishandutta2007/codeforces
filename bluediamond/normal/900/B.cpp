#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int a,b,caut;
    cin>>a>>b>>caut;
    vector<int>cif;
    while(a) {
        cif.push_back(a%10);
        a/=10;
    }
    reverse(cif.begin(),cif.end());
    int ind=-cif.size();
    for(int j=1;j<=(int)1e5;j++) {
        cif.push_back(0);
    }
    int rezid=0;
    for(auto x:cif) {
        rezid=10*rezid+x;
        int cur=rezid/b;
        rezid%=b;
        ind++;
        if(cur==caut && ind>0) {
            cout<<ind<<"\n";
            return 0;
        }
       /// cout<<cur;
    }
    cout<<"-1\n";
    return 0;
}
/**


**/
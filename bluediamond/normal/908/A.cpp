#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    string a;
    cin>>a;
    int ans=0;
    for(auto x:a) {
        if(x=='1') ans++;
        if(x=='3') ans++;
        if(x=='5') ans++;
        if(x=='7') ans++;
        if(x=='9') ans++;
        if(x=='a') ans++;
        if(x=='e') ans++;
        if(x=='i') ans++;
        if(x=='o') ans++;
        if(x=='u') ans++;
    }
    cout<<ans<<"\n";
    return 0;
}
/**


**/
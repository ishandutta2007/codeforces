#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int n,x;
set<int>s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>x;
        s.insert(x);
    }
    if(s.size()==1) {
        cout<<"YES\n";
        return 0;
    }
    if(s.size()==2) {
        cout<<"YES\n";
        return 0;
    }
    if(s.size()==3) {
        set<int>::iterator it=s.begin();
        int a=*it; it++;
        int b=*it; it++;
        int c=*it;
   //     cout<<a<<" "<
        if(c-b==b-a) {
            cout<<"YES\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}
/**


**/
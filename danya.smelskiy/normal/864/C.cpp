#include <bits/stdc++.h>
using namespace std;
long long a,b,f,k;

 main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>a>>b>>f>>k;
    long long last=0;
    long long kol=b;
    long long ans=0;
    if (b<f || b<a-f) {
        cout<<"-1";
        return 0;
    }
    for (int i=1;i<=k;++i) {
        if (last==0) {
            if (f>kol) {
                cout<<"-1";
                return 0;
            }
            if (a>kol) {
                ++ans;
                kol=b-(a-f);
            } else if (i<k && a+a-f>kol) {
                ++ans;
                kol=b-(a-f);
            } else {
                kol-=a;
            }
        } else {
            if (a-f>kol) {
                cout<<"-1";
                return 0;
            }
            if (a>kol) {
                ++ans;
                kol=b-f;
            } else if (i<k && a+f>kol) {
                ++ans;
                kol=b-f;
            } else kol-=a;

        }
        last=1-last;
    }
    cout<<ans;
}
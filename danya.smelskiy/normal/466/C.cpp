#include <bits/stdc++.h>
using namespace std;
long long n,ans,kol,kolvo,last,a[500005];
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        kol+=a[i];
    }
    last=0;
    for (int i=n;i>1;--i){
        last+=a[i];
        if (last==kol/3) ++kolvo;
    }
    last=0;
    if (kol%3!=0) {
        cout<<"0";
        return 0;
    }
    for (int i=1;i<=n-2;++i){
            last+=a[i];
            if (last==kol/3 && kol-last!=kol/3 && kolvo>0){
               if (ans+kolvo>0) ans+=kolvo;
            } else if (kol-last==kol/3 && last==kol/3 && kolvo>1){
                --kolvo;
                if (ans+kolvo>0)
                ans+=kolvo;
            } else if (kol-last==kol/3) --kolvo;
    }
    cout<<ans;
}
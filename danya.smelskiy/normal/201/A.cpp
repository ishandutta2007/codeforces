#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
    cin>>n;
    if (n==1) cout<<1;
    else if (n==2) cout<<3;
    else if (n==3) cout<<5;
    else if (n==4) cout<<3;
    else if (n==5) cout<<3;
    else {
        if (n&1) --n;
        for (int i=5;;i+=2) {
            int kol=(i*i+1)/2-1;
            if (kol<n) continue;
            if (kol==n) {
                cout<<i;
                return 0;
            }
            int kol2=(kol-i/2-i/2)/4;
            int kol3=(i/2+i/2);
            int z=kol-n;
            int zz=z/4;
            if (kol2>=zz) z-=zz*4;
            else z-=kol2*4;
            zz=z/2;
            if (kol3>=zz) z-=zz*2;
            else z-=kol3*2;
            if (!z) {
                cout<<i;
                return 0;
            }
        }
    }
}
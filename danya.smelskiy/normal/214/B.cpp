#include <bits/stdc++.h>
using namespace std;

int n,kol[10];
int all;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        int x;
        cin>>x;
        ++kol[x];
        all=(all+x)%3;
    }
    if (!kol[0]) {
        cout<<"-1";
        return 0;
    }
    if (kol[0]==n) {
        cout<<"0";
        return 0;
    }
    if (all==0) {
        for (int i=9;i>=0;--i)
            while (kol[i]--) cout<<i;
        return 0;
    }
    for (int i=0;i<=9;++i) if (kol[i] && i%3==all) {
        bool t=false;
        --kol[i];
        for (int j=1;j<=9;++j) if (kol[j]) t=true;
        if (t==false) {
            ++kol[i];
            continue;
        }
        for (int j=9;j>=0;--j) while (kol[j]--) cout<<char(j+'0');
        exit(0);
    }
    for (int i=0;i<=9;++i) if (kol[i]) {
        --kol[i];
        for (int j=0;j<=9;++j) if (kol[j] && (i+j)%3==all){
            --kol[j];
            bool t=false;
            for (int z=1;z<=9;++z) if (kol[z]) t=true;
            if (t==false) {
                ++kol[j];
                continue;
            }
            for (int z=9;z>=0;--z)
                while (kol[z]--) cout<<z;
            exit(0);
        }
        ++kol[i];
    }
    cout<<"0";
}
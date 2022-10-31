#include <bits/stdc++.h>
using namespace std;

int x;
int x1,x2;

int main(){
    cin>>x;
    cin>>x1>>x2;
    long long tm=x1*60+x2;
    int ans=0;
    while (true) {
        x1=tm/60;
        x2=tm%60;
        if (x1%10==7 || x2%10==7) {
            cout<<ans;
            return 0;
        }
        ++ans;
        tm-=x;
        if (tm<0) tm+=(24*60);
    }
}
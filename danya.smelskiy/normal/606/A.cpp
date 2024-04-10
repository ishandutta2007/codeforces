#include <bits/stdc++.h>
using namespace std;
long long a[5],b[5];
int main(){
    cin>>a[1]>>a[2]>>a[3];
    cin>>b[1]>>b[2]>>b[3];
    while (true){
        bool t=false;
        for (int i=1;i<=3;++i){
            if (a[i]>b[i]+1)
            for (int j=1;j<=3;++j)
            if (i!=j){
                if (a[j]<b[j]){
                    a[j]++;
                    t=true;
                    a[i]-=2;
                    break;
                }
            }
        }
        if (!t) break;
    }
    if (a[1]>=b[1] && a[2]>=b[2] && a[3]>=b[3]) cout<<"Yes";
    else cout<<"No";
}
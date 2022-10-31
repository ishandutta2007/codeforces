#include <bits/stdc++.h>
using namespace std;
int a[5];
int ans;
int main(){
    cin>>a[1]>>a[2]>>a[3]>>a[4];
    for (int i=1;i<=4;++i){
        for (int j=1;j<=4;++j)
            if (i!=j && a[i]==a[j]) a[i]=0;
    }
    for (int i=1;i<=4;++i)
        if (a[i]==0) ++ans;
        cout<<ans;
}
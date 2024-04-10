#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000001];
int b[1000001];
int kol1[100];
int kol2[100];
int ans1,ans2;
int x,y;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        ++kol1[a[i]];
    }
    for (int i=1;i<=n;++i){
        cin>>b[i];
        ++kol2[b[i]];
    }
    for (int i=1;i<=5;++i){
        x=kol1[i];
        y=kol2[i];
        if ((x+y)%2==1){
            cout<<"-1";
            return 0;
        }
        if (x>y) {
            ans1+=(x-y)/2;
        } else ans2+=(y-x)/2;
    }
    if (ans1!=ans2) cout<<"-1";
    else cout<<ans1;
}
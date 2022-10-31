#include <bits/stdc++.h>
using namespace std;
int a[10];
int t;
bool bear,slon;
int main(){
    for (int i=1;i<=6;++i)
        cin>>a[i];
    sort(a+1,a+6+1);
    if (a[1]==a[2] && a[2]==a[3] && a[3]==a[4]) t=1;
    else if (a[2]==a[3] && a[3]==a[4] && a[4]==a[5]) t=2;
    else if (a[3]==a[4] && a[4]==a[5] && a[5]==a[6]) t=3;
    else {
        cout<<"Alien";
        return 0;
    }
    if (t==1){
        if (a[5]==a[6]) slon=true;
        else if (a[5]!=a[6]) bear=true;
    } else if (t==2){
        if (a[1]==a[6]) slon=true;
        else if (a[1]!=a[6]) bear=true;
    } else {
        if (a[1]==a[2]) slon=true;
        else if (a[1]!=a[2]) bear=true;
    }
    if (slon==true) cout<<"Elephant";
    else if (bear==true) cout<<"Bear";
    else cout<<"Alien";
}
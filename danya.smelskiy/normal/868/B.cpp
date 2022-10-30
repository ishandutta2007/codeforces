#include <bits/stdc++.h>
using namespace std;

int h,m,s,t1,t2;

int main(){
    cin>>h>>m>>s>>t1>>t2;
    if (t1>t2) swap(t1,t2);
    int x2=t1*5;
    int y2=t2*5;
    if ((h>=t1 && h<t2) || (m>=x2 && m<y2) || (s>=x2 && s<y2)) {
    } else {
        cout<<"YES";
        return 0;
    }
    if ((h>=t2 || h<t1) || (m>=y2 || m<x2) || (s>=y2 || s<x2)) {
    } else {
        cout<<"YES";
        return 0;
    }
    cout<<"NO";
}
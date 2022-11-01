#include<bits/stdc++.h>
using namespace std;

int a;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>a;
    cout<<(a&(1<<5))+((a&1)<<4)+((a&4)<<1)+((a&8)>>1)+(a&2)+((a&16)>>4)<<endl;

    return 0;
}
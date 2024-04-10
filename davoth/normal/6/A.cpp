#include<bits/stdc++.h>
/*#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>*/
using namespace std;
int main(){
    int n[4],a=0;
    for(int i=0;i<4;i++) cin>>n[i];
    sort(n,n+4);
    for(int i=0;i<2;i++){
        if(n[i]+n[i+1]==n[i+2]){
            a=1;
        }else if(n[i]+n[i+1]>n[i+2]){
            cout<<"TRIANGLE";
            return 0;
        }
    }
    if(a==1) cout<<"SEGMENT";
    else cout<<"IMPOSSIBLE";
    return 0;
}
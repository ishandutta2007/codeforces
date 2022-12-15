#include <stdio.h>
#include<iostream>
#include<string>
#include <algorithm>
#include <string.h>
#include <vector>
#define LL long long
#define MAX 100005

using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,x;
        cin>>n>>x;
        if(n==1||n==2) cout<<1<<endl;
        else cout<<(n-3)/x+2<<endl;
    }
    return 0;
}
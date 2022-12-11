#include<bits/stdc++.h>
using namespace std;
const int N=3e5+50;
int n;char s[100];
int main(){
    scanf("%d",&n);
    for(int i=2;i<=n;i++)if(n%i==0)cout<<i<<n/i,exit(0);
    return 0;
}
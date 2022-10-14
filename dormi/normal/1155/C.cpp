/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on April 22, 2019, 10:20 AM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli gcd(lli a,lli b){
    if(b==0)return a;
    return gcd(b,a%b);
}
/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    lli last;
    cin>>last;
    lli in;
    lli gc=0;
    lli first=last;
    for(int i=1;i<n;i++){
        cin>>in;
        gc=gcd(gc,in-last);
        last=in;
    }
    for(int i=0;i<m;i++){
        cin>>in;
        if(gc%in==0){
            printf("YES\n%lli %d\n",first,i+1);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
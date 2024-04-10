/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: allen
 *
 * Created on March 21, 2019, 11:34 AM
 */

#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    lli arr[n+1];
    arr[0]=0;
    lli tot=0;
    lli prev=INT_MAX;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=n;i>0;i--){
        prev=max((lli)0,min(prev-1,arr[i]));
        tot+=prev;
    }
    printf("%lli",tot);
    return 0;
}
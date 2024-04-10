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
    string s;
    cin>>n>>s;
    lli tot=0;
    for(int i=0;i<n;i++){
        if((s[i]-'0')%2==0){
            tot+=i+1;
        }
    }
    printf("%lli",tot);
    return 0;
}
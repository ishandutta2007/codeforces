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

/*
 * 
 */
int main(int argc, char** argv) {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string s;
    cin>>s;
    char least=s[n-1];
    int loc=n-1;
    for(int i=n-2;i>=0;i--){
        if(s[i]>least){
            printf("YES\n%d %d\n",i+1,loc+1);
            return 0;
        }
        if(s[i]<least){
            least=s[i];
            loc=i;
        }
    }
    printf("NO\n");
    return 0;
}
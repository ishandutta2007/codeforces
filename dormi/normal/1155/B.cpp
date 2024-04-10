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
    int vasyaremove=(n-11)/2;
    int petyamove=(n-11)/2;
    int removed=0;
    for(int i=0;i<n;i++){
        if(s[i]=='8'){
            if(petyamove){
            petyamove-=1;
            removed+=1;
            }
            else{
                if(i-removed<=vasyaremove){
                    printf("YES\n");
                    return 0;
                }
            }
        }
        else{
            if(vasyaremove){
            vasyaremove-=1;
            removed+=1;
            }
        }
    }
    printf("NO\n");
    return 0;
}
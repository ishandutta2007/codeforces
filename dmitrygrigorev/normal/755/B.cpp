#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <bits/stdc++.h>
#include <math.h>
#include <fstream>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    int n, m;
    set<string> myset;
    string s;
    cin >> n >> m;
    for (int i=0;i<n;i++){
        cin >> s;
        myset.insert(s);
    }
    int f1 = n;
    int f2 = 0;
    int s1 = m;
    int s2 = 0;
    for (int i=0;i<m;i++){
        cin >> s;
        if (myset.count(s)){
            f1 --;
            s1 --;
            f2 ++;
        }
    }
    bool moves = true;
    while (true){
        if (moves){
            if (f2 > 0){
                f2 --;
            }
            else{
                if (f1 > 0){
                f1 --;
                }
                else{
                    break;
                }
            }
            moves = false;
        }
        else{
            if (f2 > 0){
                f2 --;
            }
            else{
                if (s1 > 0){
                s1 --;
                }
                else{
                    break;
                }
            }
            moves = true;
        }
    }
    if (moves){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    return 0;
}
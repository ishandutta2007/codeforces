#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stdlib.h>
#include <cmath>
#include <math.h>
#include <fstream>
#include <bitset>
#include <time.h>
#define int long long
using namespace std;
int n, ai, m;
vector<int> moneys, data;
vector<int> first, second, third;
vector<bool> used;
bool comp(int f, int s){
    if (moneys[f] < moneys[s]) return true;
    return false;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        moneys.push_back(ai);
        used.push_back(false);
    }
    for (int i=0;i<2*n;i++){
        cin >> ai;
        if (ai == 1){
            first.push_back(i % n);
        }
        if (ai == 2){
            second.push_back(i % n);
        }
        if (ai == 3){
            third.push_back(i % n);
        }
    }
    sort(first.begin(), first.end(), comp);
    sort(second.begin(), second.end(), comp);
    sort(third.begin(), third.end(), comp);
    int uf = 0;
    int us = 0;
    int ut = 0;
    cin >> m;
    for (int i = 0;i<m;i++){
        cin >> ai;
        if (ai == 1){
            while (uf < first.size() && used[first[uf]]){
                uf ++;
            }
            if (uf == first.size()) cout << -1 << " ";
            else {cout << moneys[first[uf]] << " ";
            used[first[uf]] = true;}
        }
        if (ai == 2){
            while (us < second.size() && used[second[us]]){
                us ++;
            }
            if (us == second.size()) cout << -1 << " ";
            else {cout << moneys[second[us]] << " ";
            used[second[us]] = true;}
        }
        if (ai == 3){
            while (ut < third.size() && used[third[ut]]){
                ut ++;
            }
            if (ut == third.size()) cout << -1 << " ";
            else {cout << moneys[third[ut]] << " ";
            used[third[ut]] = true;}
        }
    }
    return 0;
}
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
#define int long long
using namespace std;
int n, ai;
vector<int> d1, d2;
vector<vector<int> > m1;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        d1.push_back(ai);
    }
    for (int i=0;i<n;i++){
        cin >> ai;
        d2.push_back(ai);
    }
    for (int i=0;i<n;i++){
        vector<int> help;
        help.push_back(d1[i]);
        help.push_back(d2[i]);
        help.push_back(i+1);
        m1.push_back(help);
    }
    sort(m1.begin(), m1.end(), greater<vector<int> >());
    cout << n/2 + 1 << endl;
    cout << m1[0][2] << " ";
    int st = 1;
    if (n % 2 == 0) {cout << m1[1][2] << " "; st=2;}
    for (int i=st;i<n;i+=2){
        if (m1[i][1] >= m1[i+1][1]){
            cout << m1[i][2] << " ";
        }
        else cout << m1[i+1][2] << " ";
    }
    return 0;
    }
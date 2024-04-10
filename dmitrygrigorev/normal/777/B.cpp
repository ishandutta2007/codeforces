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
using namespace std;
int main()
{
    std::ios::sync_with_stdio(false);
    string s1, s2;
    int n;
    cin >> n;
    cin >> s1;
    cin >> s2;
    vector<char> v1, v2;
    vector<bool> used;
    for (int i=0;i<n;i++){
        used.push_back(false);
        v1.push_back(s1[i]);
        v2.push_back(s2[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int answer = 0;
    for (int i=0;i<n;i++){
        bool go = false;
        for (int j=0;j<n;j++){
            if (v2[j] >= v1[i] && !used[j]){
                go = true;
                used[j] = true;
                answer += 1;
                break;
            }
        }
        if (!go){
            break;
        }
    }
    int answer1 = 0;
    for (int i=0;i<n;i++){
        used[i]= false;
    }
    for (int i=0;i<n;i++){
        bool go = false;
        for (int j=0;j<n;j++){
            if (v2[j] > v1[i] && !used[j]){
                go = true;
                used[j] = true;
                answer1 += 1;
                break;
            }
        }
        if (!go){
            break;
        }
    }
    cout << n - answer << endl;
    cout << answer1 << endl;
    return 0;
}
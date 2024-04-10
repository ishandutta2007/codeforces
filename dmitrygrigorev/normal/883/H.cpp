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
#include <queue>
#define int long long
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> mm;
    for (int i=0; i < s.size(); i++){
        mm[s[i]]++;
    }
    int N = 0;
    vector<char> nechet;
    for (map<char, int>::iterator it = mm.begin(); it != mm.end(); it++){
        pair<char, int> p = *it;
        if (p.second % 2 != 0){
            N++;
            nechet.push_back(p.first);
        }
    }
    int answer = 0;
    for (int del=1; del <= s.size(); del++){
        int wanted = s.size() / del;
        if (del % 2 == 0) wanted = 0;
        if ((N <= wanted && (wanted-N) % 2 == 0) && s.size() % del == 0) answer = del;
    }
    //cout << answer << endl;
    cout << s.size() / answer << endl;
    map<char, int> del;
    int u=0, U=0;
    string nqs;
    for (int i=0; i < s.size(); i++){
        if (mm[s[i]] % 2 != 0) mm[s[i]]--;
        else nqs += s[i];
    }
    for (int i=0; i < s.size() / answer; i++){
        string aa;
        for (int j=0; j < answer/2; j++){
            while (del[nqs[u]] > 0){
                del[nqs[u]]--;
                u++;
            }
            aa += nqs[u];
            del[nqs[u]]++;
            u++;
        }
        while (del[nqs[u]] > 0){
            del[nqs[u]]--;
            u++;
        }
        if (answer % 2 != 0){
            if (U == nechet.size()){
                aa += nqs[u];
                u++;
                del[nqs[u-1]]++;
                nechet.push_back(nqs[u-1]);
            }
            else{
                aa += nechet[U];
                U++;
            }
        }
        for (int j=answer/2-1; j >= 0; j--){
            aa += aa[j];
        }
        cout << aa << " ";
    }
    return 0;
}
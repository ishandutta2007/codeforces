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
#define double long double
using namespace std;
int n, ai;
vector<vector<int> > data;
vector<int> peoples;
int gb(int x, int y, int p, int q){
    int l = 0;
    int r = 1100000000;
    while (r - l > 1){
        int m = (l + r) / 2;
        int nx = p * m;
        int ny = q * m;
        if (nx >= x && ny >= y && (nx - x <= ny - y)) r = m;
        else l = m;
    }
    return (q * r - y);
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=0;i<5;i++){
        peoples.push_back(0);
    }
    for (int i=0;i<n;i++){
        vector<int> help;
        for (int j=0;j<5;j++){
            cin >> ai;
            help.push_back(ai);
            if (ai != -1) peoples[j] ++;
        }
        data.push_back(help);
    }
    int ll = -1;
    int rr = 1000000008;
    int s1 = 0;
    int s2 = 0;
    int res1[5], res2[5], st[5];
    for (int i=0;i<5;i++){
        res1[i] = 0;
        res2[i] = 0;
    }
    for (int i=0;i<5;i++){
        int nc;
        double dole = (double) peoples[i] / (double) n;
        if (dole > (double)1/(double)2) nc = 500;
        else if (dole > (double)1/(double)4) nc = 1000;
        else if (dole > (double)1/(double)8) nc = 1500;
        else if (dole > (double)1/(double)16) nc = 2000;
        else if (dole > (double)1/(double)32) nc = 2500;
        else nc = 3000;
        st[i] = nc;
        if (data[0][i] != -1){
            s1 += nc - nc / 250 * data[0][i];
            res1[i] = nc - nc / 250 * data[0][i];
        }
        if (data[1][i] != -1){
            s2 += nc - nc / 250 * data[1][i];
            res2[i] = nc - nc / 250 * data[1][i];
        }
    }
    int md = -1;
    while (md < 10000){
        md ++;
        int won = 0;
        for (int i=0;i<5;i++){
            if (data[0][i] == data[1][i]) continue;
            if (data[0][i] == -1 || (data[0][1] != -1 && data[1][i] != -1 && data[1][i] < data[0][i])){
                int mmd = md;
                if (data[0][i] == -1) mmd = 0;
                int nc;
                double dole = (double) (peoples[i] + mmd) / (double) (n+md);
                if (dole > (double)1/(double)2) nc = 500;
                else if (dole > (double)1/(double)4) nc = 1000;
                else if (dole > (double)1/(double)8) nc = 1500;
                else if (dole > (double)1/(double)16) nc = 2000;
                else if (dole > (double)1/(double)32) nc = 2500;
                else nc = 3000;
                int v1, v2;
                v2 = nc - (nc) * data[1][i] / 250;
                if (data[0][i] == -1) v1 = 0;
                else v1 = nc - (nc) * data[0][i] / 250;
                int wons = (res2[i] - res1[i]) - (v2 - v1);
                won += wons;
            }
            else{
                int nc;
                double dole = (double) peoples[i] / (double) (n + md);
                if (dole > (double)1/(double)2) nc = 500;
                else if (dole > (double)1/(double)4) nc = 1000;
                else if (dole > (double)1/(double)8) nc = 1500;
                else if (dole > (double)1/(double)16) nc = 2000;
                else if (dole > (double)1/(double)32) nc = 2500;
                else nc = 3000;
                int v1, v2;
                v1 = nc - (nc) * data[0][i] / 250;
                if (data[1][i] == -1) v2 = 0;
                else v2 = nc - (nc) * data[1][i] / 250;
                int now = (st[i] / 500);
                int wons = (v1 - v2) - (res1[i] - res2[i]);
                won += wons;
            }
        }
        bool ans = false;
        if (won > s2 - s1) ans = true;
        if (ans){
            cout << md << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
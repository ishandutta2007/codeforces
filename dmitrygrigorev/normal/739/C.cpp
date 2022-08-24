#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
#include <cstdlib>
using namespace std;
vector<double> data;
vector<vector< int> > rmq;
vector<double> a;
vector<int> first;
vector<int> second;
bool znak(double a, double b){
    if (a>0 & b > 0){
        return true;
    }
    if (a<0 & b < 0){
        return true;
    }
    return false;
}
void modificate(int number, int i, int l, int r){
    if (l >= r){
        return;
    }
    if (r - l == 1){
        if (abs(a[l]) > 0){
        rmq[i][0] =1;
        rmq[i][1] =1;
        rmq[i][2] =1;
        }
        else{
        rmq[i][0] =0;
        rmq[i][1] =0;
        rmq[i][2] =0;
        }
    }
    else{
        int m = (l + r) / 2;
        if (number < m){
        modificate(number, 2*i+1, l, m);
        }
        else{
        modificate(number,2*i+2, m, r);
        }
        second = rmq[2 * i + 2];
        first = rmq[2 * i + 1];
        if (first.size() == 0){
            rmq[i] = second;
            return;
        }
        if (second.size() == 0){
            rmq[i] = first;
            return;
        }
        int prefix;
        int suffix;
        int centr = max(first[1], second[1]);
        if (a[m-1] == 0 | a[m] == 0){
            prefix = first[0];
            suffix = second[2];
        }
        else{
            if ((a[m-1] >0 ) >= (a[m] > 0)){
                centr = max(centr, second[0] + first[2]);
                prefix = first[0];
                if (prefix == m-l){
                    prefix += second[0];
                }
                suffix = second[2];
                if (suffix == r-m){
                    suffix += first[2];
                }
            }
            else{
            prefix = first[0];
            suffix = second[2];
            }
        }
        rmq[i][0] = prefix;
        rmq[i][1] = centr;
        rmq[i][2] = suffix;
}
}
void create(int i, int l, int r){
    if (l >= r){
        return;
    }
    if (r - l == 1){
        if (abs(a[l]) > 0){
        rmq[i].push_back(1);
        rmq[i].push_back(1);
        rmq[i].push_back(1);
        }
        else{
        rmq[i].push_back(0);
        rmq[i].push_back(0);
        rmq[i].push_back(0);
        }
    }
    else{
        int m = (l + r) / 2;
        create(2 * i + 1, l, m);
        create(2*i+2, m, r);
        first = rmq[2 * i + 1];
        second = rmq[2 * i + 2];
        if (first.size() == 0){
            rmq[i] = second;
            return;
        }
        if (second.size() == 0){
            rmq[i] = first;
            return;
        }
        int prefix;
        int suffix;
        int centr = max(first[1], second[1]);
        if (a[m-1] == 0 | a[m] == 0){
            prefix = first[0];
            suffix = second[2];
        }
        else{
            if ((a[m-1] >0 ) >= (a[m] > 0)){
                centr = max(centr, second[0] + first[2]);
                prefix = first[0];
                if (prefix == m-l){
                    prefix += second[0];
                }
                suffix = second[2];
                if (suffix == r-m){
                    suffix += first[2];
                }
            }
            else{
            prefix = first[0];
            suffix = second[2];
            }
        }
        rmq[i].push_back(prefix);
        rmq[i].push_back(centr);
        rmq[i].push_back(suffix);

    }
}
int main(){
    int n, li, ri, m;
    double ai, di;
    scanf("%d", &n);
    for (int i=0;i<n;i++){
        scanf("%lf", &ai);
        data.push_back(ai);
    }
    for (int i=0;i<4*n;i++){
        vector<int> help;
        rmq.push_back(help);
    }
    for (int i=1;i<n;i++){
        a.push_back(data[i] - data[i-1]);
    }
    create(0, 0, n-1);
    cin >> m;
    if (n == 1){
        for (int i=0;i<m;i++){
            scanf("%d", &li);
            scanf("%d", &ri);
            scanf("%lf", &di);
            printf("%d ", 1);
        }
    }
    else{
    vector<int> answers;
    for (int i=0;i<m;i++){
        scanf("%d", &li);
        scanf("%d", &ri);
        scanf("%lf", &di);
        if (li > 1){
        bool change = znak(a[li-2], a[li-2] + di);
        a[li - 2] += di;
        if (!change){
        modificate(li - 2, 0, 0, n-1);
        }
        }
        bool change = znak(a[ri-1], a[ri-1] - di);
        a[ri - 1] -= di;
        if (!change){
        modificate(ri - 1, 0, 0, n-1);
        }
        answers.push_back(rmq[0][1] + 1);
    }
    for (int i=0;i<m;i++){
        printf("%d ", answers[i]);
    }
    }
    return 0;
}
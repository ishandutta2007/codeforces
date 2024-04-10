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
int n, k;
bool bs(int number){
    int nn = n;
    nn--;
    int num = number / 2;
    int lists = 0;
    if (number % 2 != 0){
        nn -= (num + 1);
        lists++;
    }
    else{
        nn -= num;
        lists++;
    }
    if (nn > 0){
        if (nn % num == 0){
            lists += nn / num;
        }
        else lists += nn/num + 1;
    }
    if (lists <= k) return true;
    return false;
}
signed main()
{
    cin >> n >> k;
    int left = 1;
    int right = n - 1;
    while (right - left > 1){
        int mid = (left + right) / 2;
        if (bs(mid)) right = mid;
        else left = mid;
    }
    cout << right << endl;
    vector<int > father;
    for (int i=0; i < n; i++){
        father.push_back(1);
    }
    int nn = n;
    nn--;
    int num = right / 2;
    int lists = 0;
    int uk = 1;
    if (right % 2 != 0){
        for (int i=0;i<=num;i++){
            father[uk] = uk-1;
            uk ++;
        }
        nn -= (num + 1);
        lists++;
    }
    else{
        for (int i=0;i<num;i++){
            father[uk] = uk-1;
            uk ++;
        }
        nn -= num;
        lists++;
    }
    while (nn > 0){
        if (nn < num){
            for (int i=0; i < nn; i++){
                if (i == 0) father[uk] = 0;
                else father[uk] = uk-1;
                uk++;
            }
            nn = 0;
        }
        else{
            nn -= num;
            for (int i=0; i < num; i++){
                if (i == 0) father[uk] = 0;
                else father[uk] = uk-1;
                uk++;
            }
        }
        lists ++;
    }
    int uu = 1;
    while (lists < k){
        if (father[uu] == 0) {uu ++;continue;}
        lists++;
        int old = father[uu];
        father[uu] = 0;
        if (uu + 1 < n && father[uu+1] == uu){
            father[uu+1] = old;
        }
    }
    for (int i=1;i<n;i++){
        cout << i + 1 << " " << father[i] + 1 << endl;
    }
    return 0;
}
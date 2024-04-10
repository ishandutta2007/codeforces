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
#include <deque>
using namespace std;
map<int, int> grundy;
int n, ai;
vector<int> data;
int LAST = 4e4;
int get(int number){
    if (grundy.count(number)) return grundy[number];
    set<int> ms;
    for (int i=0; i < 30; i++){
        int nv = (number & ((1 << i) - 1)) | (number >> (i+1));
        if (nv != number) ms.insert(get(nv));
    }
    for (int i=0; i <= 30; i++){
        if (!ms.count(i)){
            grundy[number] = i;
            return i;
        }
    }
}
int32_t main(){
    cin >> n;
    for (int i=0; i < n; i++){
        cin >> ai;
        data.push_back(ai);
    }
    grundy[0] = 0;
    int res = 0;
    for (int i=2; i < LAST; i++){
        int play = 0;
        for (int j=0; j < n; j++){
            int num = 0;
            while (data[j] % i == 0){
                num++;
                data[j] /= i;
            }
            if (num > 0) play |= (1 << (num-1));
        }
        res ^= get(play);
    }
    for (int i=0; i < n; i++){
        if (data[i] != 1){
            res ^= get(1);
            int nn = data[i];
            for (int j=0; j < n; j++){
                if (data[j] % nn == 0) data[j] = 1;
            }
        }
    }
    if (res == 0) cout << "Arpa" << endl;
    else cout << "Mojtaba" << endl;
    return 0;
}
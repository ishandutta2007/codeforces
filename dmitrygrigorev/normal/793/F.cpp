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
using namespace std;
int thread_left[100001];
int n, m, q, li, ri;
vector<vector<int> > asks, threads;
int get_answer(int ll, int rr, int ln, int now){
    for (int i=ll;i<=rr;i++){
        if (thread_left[i] >= ln && thread_left[i] <= now){
            now = i;
        }
    }
    return now;
}
int get_sqrt(int n){
    for (int i=1;i<n;i++){
        if (i*i >= n) return i;
    }
}
int get_size(int n, int k){
    int sz = 0;
    for (int i=k;i<=n;i+=k){
        sz ++;
    }
    return sz;
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> m;
    for (int i=0;i<=n;i++){
        thread_left[i] = -1;
    }
    for (int i=0;i<m;i++){
        cin >> li >> ri;
        thread_left[ri] = li;
        vector<int> help;
        help.push_back(li);
        help.push_back(ri);
        threads.push_back(help);
    }
    cin >> q;
    for (int i=0;i<q;i++){
        cin >> li >> ri;
        vector<int> help;
        help.push_back(li);
        help.push_back(ri);
        asks.push_back(help);
    }
    sort(threads.begin(), threads.end());
    int base = get_sqrt(n);
    int number = get_size(n, base);
    int next[n+1][number], answer[n+1][number];
    for (int i=0;i<=n;i++){
        for (int j=0;j<number;j++){
            next[i][j] = i;
            answer[i][j] = i;
        }
    }
    int u = 0;
    for (int i=1;i<=n;i++){
        if (threads[u][0] != i) continue;
        int un, unn;
        for (int j=u;j<m;j++){
            if (threads[j][0] != i) break;
            un = j;
        }
        unn = un;
        int u1 = number - 1;
        while (un >= u && u1 >= 0){
            int last = base * (u1 + 1);
            if (threads[un][1] <= last){
                next[i][u1] = threads[un][1];
                u1 --;
            }
            else un --;
        }
        u = unn + 1;
        if (u >= m) break;
    }
    int counter = 0;
    for (int last=base;last<=n;last+=base){
        vector<pair<int, int> > mystack;
        for (int i=n;i>=1;i--){
            int go = next[i][counter];
            while (mystack.size() > 0){
                if (mystack.back().second <= next[i][counter]){
                    go = max(go, mystack.back().first);
                    mystack.pop_back();
                }
                else break;
            }
            answer[i][counter] = go;
            pair<int, int> p = {go, i};
            mystack.push_back(p);
        }
        counter ++;
    }
    for (int i=0;i<q;i++){
        li = asks[i][0];
        ri = asks[i][1];
        if (ri - li <= base){
            cout << get_answer(li, ri, li, li) << endl;
        }
        else{
            int nn;
            for (int j=0;j<number;j++){
                if ((j + 1) * base >= li && (j + 1) * base <= ri){
                    nn = j;
                }
            }
            cout << get_answer((nn+1) * base, ri, li, answer[li][nn]) << endl;
        }
    }
    return 0;
}
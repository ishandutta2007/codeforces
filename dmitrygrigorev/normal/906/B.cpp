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
int32_t main(){
    int n, m;
    cin >> n >> m;
    int matrix[n][m];
    set<pair<int, int> > kn;
    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            matrix[i][j] = i*m + j + 1;
        }
    }
    for (int i=0; i < n-1; i++){
        for (int j=0; j < m; j++){
            int A = matrix[i][j];
            int B = matrix[i+1][j];
            kn.insert(make_pair(min(A, B), max(A, B)));
        }
    }
    for (int i=0; i < n; i++){
        for (int j=0; j < m-1; j++){
            int A = matrix[i][j];
            int B = matrix[i][j+1];
            kn.insert(make_pair(min(A, B), max(A, B)));
        }
    }
    bool sw = false;
    if (m < n){
        sw = true;
        swap(n, m);
    }
    int x[n][m];
    if (!sw){
        for (int i=0; i < n; i++){
            for (int j=0; j < m; j++){
                x[i][j] = matrix[i][j];
            }
        }
    }
    else{
        for (int i=0; i < n; i++){
            for (int j=0; j < m; j++){
                x[i][j] = matrix[j][i];
            }
        }
    }
    int ans[n][m];
    bool result = false;
    if (m > 4){
        for (int i=0; i < n; i++){
            int now = 0;
            if (i % 2 != 0) now = 1;
            for (int j=0; j < m; j++){
                if (m % 2 == 0 && j == m / 2){
                    if (i % 2 == 0) now++;
                    else now--;
                }
                ans[i][j] = x[i][now];
                now += 2;
                now %= m;
            }
        }
        result = true;
    }
    else if (m == 4){
        int A[4] = {2, 4, 1, 3};
        int B[4] = {3, 1, 4, 2};
        for (int i=0; i < n; i++){
            if (i % 2 == 0){
                for (int j=0; j < 4; j++){
                    ans[i][j] = x[i][A[j]-1];
                }
            }
            else{
                for (int j=0; j < 4; j++){
                    ans[i][j] = x[i][B[j]-1];
                }
            }
        }
        result = true;
    }
    else{
        int P = n*m;
        vector<int> q;
        for (int i=0; i < P; i++) q.push_back(i+1);
        do {
            for (int i=0; i < n; i++){
                for (int j=0; j < m; j++){
                    int ther = x[i][j];
                    ans[i][j] = q[ther-1];
                }
            }
            bool can = true;
            for (int i=0; i < n-1; i++){
                for (int j=0; j < m; j++){
                    int A = ans[i][j];
                    int B = ans[i+1][j];
                    if(kn.count(make_pair(min(A, B), max(A, B)))) can = false;
                }
            }
            for (int i=0; i < n; i++){
                for (int j=0; j < m-1; j++){
                    int A = ans[i][j];
                    int B = ans[i][j+1];
                    if(kn.count(make_pair(min(A, B), max(A, B)))) can = false;
                }
            }
            if (can){
                result = true;
                break;
            }
        } while(std::next_permutation(q.begin(), q.end()));
    }
    if (!result){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    if (!sw){
        for (int i=0; i < n; i++){
            for (int j=0; j < m; j++){
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        for (int i=0; i < m; i++){
            for (int j=0; j < n; j++){
                cout << ans[j][i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//#define int long long
//typedef long long int;


const int Log = 18, Max = 1e5+4;
int memoMin[Log][Max+Max];
int memoMax[Log][Max+Max];
int logTwo[Max+Max] = {0};
int res[Max+Max];
int rangeLeft[Max+Max];
int rangeRight[Max+Max];
int sums[Max+Max] = {0};

void resetMin(vector<int> &arr) {
    int n = arr.size();
    for(int j = 0; j < Log; ++j) {
        for(int i = 0; i < n; ++i) {
            if(i+(1<<j)-1<n) {
                memoMin[j][i] = (j?min(memoMin[j-1][i], memoMin[j-1][i+(1<<(j-1))]):arr[i]);
            } else break;
        }
    }
}
int queryMin(int l, int r) {
    int j = logTwo[r-l+1];
    return min(memoMin[j][l], memoMin[j][r-(1<<j)+1]);
}


void resetMax(vector<int> &arr) {
    int n = arr.size();
    for(int j = 0; j < Log; ++j) {
        for(int i = 0; i < n; ++i) {
            if(i+(1<<j)-1<n) {
                memoMax[j][i] = (j?max(memoMax[j-1][i], memoMax[j-1][i+(1<<(j-1))]):arr[i]);
            } else break;
        }
    }
}
int queryMax(int l, int r) {
    int j = logTwo[r-l+1];
    return max(memoMax[j][l], memoMax[j][r-(1<<j)+1]);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    if(n == 1) {
        cout << "0\n";
        return 0;
    }
    for(int i = 2; i <= n+n; ++i) logTwo[i] = 1 + logTwo[i/2];
    vector<int> arr(n);
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<vector<int>> Left(Log, vector<int>(n+n));
    vector<vector<int>> Right(Log, vector<int>(n+n));
    for(int i = 0; i < n+n; ++i) {
        Left[0][i] = max(0, i-arr[i%n]);
        Right[0][i] = min(n+n-1, i+arr[i%n]);
    }
    for(int j = 1; j < Log; ++j) {
        resetMin(Left[j-1]);
        resetMax(Right[j-1]);
        for(int i = 0; i < n+n; ++i) {
            Left[j][i] = queryMin(Left[j-1][i], Right[j-1][i]);
            Right[j][i] = queryMax(Left[j-1][i], Right[j-1][i]);
        }
    }
    for(int i = 0; i < n+n; ++i) {
        res[i] = n+3;
        rangeLeft[i] = i;
        rangeRight[i] = i;
    }
    for(int j = Log-1; j >= 0; --j) {
        resetMin(Left[j]);
        resetMax(Right[j]);
        for(int i = 0; i < n+n; ++i) {
            int &currL = rangeLeft[i];
            int &currR = rangeRight[i];
            int &sum = sums[i];
            int newL = queryMin(currL, currR);
            int newR = queryMax(currL, currR);
            if(newR-newL+1 < n) {
                currL = newL;
                currR = newR;
                sum += (1<<j);
            } else {
                res[i%n] = min(res[i%n], sum +(1<<j));
            }
        }
    }
    for(int i = 0; i < n; ++i) {
        cout << res[i] << ' ';
    }
    cout << '\n';
    return 0;
}
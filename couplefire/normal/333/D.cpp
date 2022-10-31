#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

int grid[MAXN][MAXN];
int arr[MAXN*MAXN] = {0};
int n, m;

bool check(int mid){
    bitset<MAXN> bit[MAXN];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(grid[i][j] >= mid) bit[i].set(j, 1);
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if((bit[i]&bit[j]).count() >= 2) return true;
        }
    }
    return false;
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
            arr[i*m+j] = grid[i][j];
        }
    }
    sort(arr, arr+MAXN*MAXN);
    int lo = 0, hi = MAXN*MAXN-1;
    while(lo < hi){
        int mid = lo+(hi-lo+1)/2;
        if(!check(arr[mid])){
            hi = mid-1;
        }
        else lo = mid;
    }
    cout << arr[lo] << endl;
}
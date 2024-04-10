#include <bits/stdc++.h>
using namespace std;

int main(){
    //freopen("a.in", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    int grid[n][m];
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> grid[i][j];
        }
    }
    int pow2[10];
    pow2[0] = 1;
    for(int i = 1; i<10; i++) pow2[i] = 2*pow2[i-1];
    int hi = 1000000005;
    int lo = 0;
    int first, second;
    while(lo < hi){
        int mid = lo+(hi-lo+1)/2;
        int whatever[257];
        fill(whatever, whatever+257, -1);
        for(int i = 0; i<n; i++){
            int cur = 0;
            for(int j = 0; j<m; j++){
                if(grid[i][j] < mid) cur += pow2[m-1-j];
            }
            whatever[cur] = i;
        }
        bool work = false;
        for(int i = 0; i<pow2[m]; i++){
            for(int j = 0; j<pow2[m]; j++){
                if((i & j) != 0) continue;
                if(whatever[i] >= 0 && whatever[j] >= 0){
                    work = true;
                    first = whatever[i];
                    second = whatever[j];
                }
            }
        }
        if(work) lo = mid;
        else hi = mid-1;
    }
    cout << min(first+1,n) << " " << min(second+1, n) << endl;
}
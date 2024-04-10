#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    int t, bl[1000], want[50];
    memset(bl, -1, sizeof(bl));
    for(int i = 0; i < k ; i++){
        cin >> t;t--;
        bl[t] = i;
        want[i] = t;
    }
    int now = 0;
    for(int i = 0; i < k; i++){
        int cnt = 1;
        cout << want[i] + 1;
        for(;now < n*k && cnt < n; now++)
            if(bl[now] == -1){
                cnt++;
                cout << ' ' << now+1;
            }
        cout << endl;
    }
    return 0;
}
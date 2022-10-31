#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int arr[1000], no[1000];
int cmp(int a, int b){
    return arr[a] < arr[b];
}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int k = 0; k < n; k++){
        cin >> arr[k];
        no[k] = k;
    }
    sort(no, no+n, cmp);
    cout << arr[no[n-m]] << endl;
    for(int k = 1; k <= m; k++)
        cout << no[n-k]+1 << ' ';
    cout << endl;
    return 0;
}
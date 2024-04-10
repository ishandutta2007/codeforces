#include <iostream>
#include <algorithm>
using namespace std;
int cmp(int a, int b){return a > b;}
int main(){
    int n, m, arr[50];
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+n, cmp);
    int cnt = 0;
    for(int num = 0; num < n && cnt < m; num++){
        for(int k = num; k < n && cnt < m; k++){
            cnt++;
            cout << num +1;
            for(int i = 0; i < num; i++) cout << ' ' << arr[i];
            cout << ' ' << arr[k] << endl;
        }
    }
    return 0;
}
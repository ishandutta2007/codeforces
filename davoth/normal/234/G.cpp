#include <bits/stdc++.h>
using namespace std;
int log(int n){
    int cnt=0;
    while(n>1){
        n=ceil(n/2.0);
        ++cnt;
    }
    return cnt;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    cout << log(n) << '\n';
    vector<int> a[log(n)];
    for(int i=0; i<log(n); i++){
        for(int j=0; j<n; j++){
            if(j/(int)pow(2,i)%2==0){
                a[i].push_back(j+1);
            }
        }
    }
    for(int i=0; i<log(n); i++){
        cout << a[i].size() << ' ';
        for(int j=0; j<a[i].size(); j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}
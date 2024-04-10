#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if (n == 4 || n == 5 || n == 1 || n == 2){
        cout<<1<<endl;
        return 0;
    }
    int ok1 = 4,ok2 = 5;
    while (ok1 < 1000000){
        int okk1 = 1 + ok1 + ok2;
        int okk2 = 1 + ok1 + ok1;
        ok1 = okk1;
        ok2 = okk2;
        if (n == okk1 || n == okk2){
            cout<<1<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
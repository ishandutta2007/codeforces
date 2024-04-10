#include <bits/stdc++.h>
using namespace std;
const int maxn = 100+5;
int main(){
    int n;
    cin>>n;
    while (n--){
        int x;
        cin>>x;
        if (x){
            puts("HARD");
            return 0;
        }
    }
    puts("EASY");
    return 0;
}
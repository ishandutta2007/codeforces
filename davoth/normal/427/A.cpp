#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,cnt=0,l=0;
    cin >> n;
    while(n--){
        int temp;
        cin >> temp;
        if(temp!=-1) l+=temp;
        else{
            if(l) l--;
            else cnt++;
        }
    }
    cout << cnt;
    return 0;
}
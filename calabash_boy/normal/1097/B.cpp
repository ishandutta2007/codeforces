#include <bits/stdc++.h>
using namespace std;
const int maxn = 180 * 15 + 100;
int a[maxn];
int main(){
    int n;
    cin>>n;
    int sum = 0;
    for (int i=0;i<n;i++){
        cin>> a[i];
        sum += a[i];
    }
    for (int mask=0;mask< (1 << n);mask++){
        int temp = 0;
        for (int i=0;i<n;i++){
            if (mask & (1 << i)){
                temp += a[i];
            }
        }
        int rest = sum - temp;
        if (abs(rest - temp)%360 == 0){
            return puts("YES"),0;
        }
    }
    puts("NO");
    return 0;
}
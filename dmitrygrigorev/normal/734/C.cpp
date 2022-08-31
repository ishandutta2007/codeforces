#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
vector<long long> times, money1, counts, money2;
int bs(long long moneys){
    int l = -1;
    int r = money2.size();
    while (r - l > 1){
        int mid = (l + r) / 2;
        if (money2[mid] <= moneys){
            l = mid;
        }
        else{
            r = mid;
        }
    }
    return l;
}
int main(){
    long long n,x, s, ai; 
    int m, k;
    cin >> n >> m >> k >> x >> s;
    for (int i=0;i<m;i++){
        cin >> ai;
        times.push_back(ai);
    }
    for (int i=0;i<m;i++){
        cin >> ai;
        money1.push_back(ai);
    }
    for (int i=0;i<k;i++){
        cin >> ai;
        counts.push_back(ai);
    }
    for (int i=0;i<k;i++){
        cin >> ai;
        money2.push_back(ai);
    }
    long long ans = x * n;
    int index = bs(s);
    if (index != -1){
    ans = min(ans, x * (n - counts[index]));
    }
    for (int i=0;i<m;i++){
        long long mm = s - money1[i];
        if (mm < 0){
            continue;
        }
        else{
            int index = bs(mm);
            if (index == -1){
                ans = min(ans, times[i] * n);
                continue;
            }
            ans = min(ans, times[i] * (n - counts[index]));
        }
    }
    cout.precision(20);
    cout << ans << endl;
    return 0;
}
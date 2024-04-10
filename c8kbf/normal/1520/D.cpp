#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <map>
#include <utility>
#include <cstdlib>
#include <tuple>
#include <iterator>
#include <climits>
#include <queue>
#include <functional>
#include <set>
 
#define ll long long
 
using namespace std;
 
int main(){
    int t; cin >> t;
    for (int i= 0; i < t; i++){
        int n; cin >> n; int a[n]; long long count = 0;
        
        map <int, int> store;

        for (int e= 0; e < n; e++){
            cin >> a[e];
            store[a[e]-e]+=1;
        }
        for (auto w : store){
            int c = w.second; count += ((1LL*c*(c-1))/2);
        }
 
        cout << count << "\n";
    }
}
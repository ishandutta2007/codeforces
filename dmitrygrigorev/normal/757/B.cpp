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
int n, ai;
int main(){
    std::ios::sync_with_stdio(false);
    int used[100010];
    for (int i=0;i<100010;i++){
        used[i] = 0;
    }
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        used[ai] += 1;
    }
    int maximum = 1;
    for (int i = 2;i<=100005;i++){
        int counter = 0;
        for (int j=i;j<=100005;j+=i){
            counter += used[j];
        }
        maximum = max(counter, maximum);
    }
    cout << maximum << endl;
    return 0;
}
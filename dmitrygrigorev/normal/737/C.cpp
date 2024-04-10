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
int n, s, ai;
vector<int> data;
int main(){
    std::ios::sync_with_stdio(false);
    cin >> n >> s;
    int answer = 0;
    for (int i=0;i<n;i++){
        cin >> ai;
        if (i == s-1){
            if (ai!=0){
                answer ++;
            }
        }
        else{
            if (ai==0){
                data.push_back(n);
            }
            else{
                data.push_back(ai);
            }
        }
    }
    sort(data.begin(), data.end());
    int now = 1;
    int counter = 0;
    int cc = 0;
    while (cc<n-1){
        if (data[counter] < now){
            counter ++;
        }
        else{
            if (data[counter] > now){
            answer ++;
            }
            else{
                counter ++;
            }
            now += 1;
        }
        cc ++;
    }
    cout << answer << endl;
    return 0;

}
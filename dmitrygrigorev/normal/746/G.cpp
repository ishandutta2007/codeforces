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
vector<long long> data;
int main(){
    long long n, t, k, ai;
    cin >> n >> t >> k;
    for (int i=0;i<t;i++){
        cin >> ai;
        data.push_back(ai);
    }
    if (t==1){
        if (k != data[0]){
            cout << -1 << endl;
        }
        else{
            cout << n << endl;
            for (int i=2;i<=n;i++){
                cout << 1 << " " << i << endl;
            }
        }
        return 0;
    }
    long long minimum = 0;
    for (int i=1;i<t;i++){
        if (data[i] < data[i-1]){
            minimum += data[i-1] - data[i];
        }
    }
    minimum += data[t-1];
    long long maximum = 0;
    for (int i=0;i<t-1;i++){
        maximum += data[i] - 1;
    }
    maximum += data[t-1];
    if (k < minimum | k > maximum){
        cout << -1 << endl;
        return 0;
    }
    int diff = k - minimum;
    cout << n << endl;
    for (int i=0;i<data[0];i++){
        cout << 1 << " " << i + 2 << endl;
    }
    int counter = 1 + data[0]+ 1;
    for (int i=1;i<data.size();i++){
        cout << counter - data[i-1] << " " << counter << endl;
        counter ++;
        int ukaz = 0;
        for (int j=1;j<data[i];j++){
            if (ukaz+1 >= data[i-1]){
                cout << counter - j - 1 << " " << counter << endl;
                counter ++;
            }
            else{
                if (diff == 0){
                    ukaz ++;
                    cout << counter - j - data[i-1] + ukaz << " " << counter << endl;
                    counter ++;
                }
                else{
                    cout << counter - j - data[i-1] << " " << counter << endl;
                    if (j >= data[i] - data[i-1] + 1){
                    diff --;
                    }
                    counter ++;
                }
            }
        }
    }
    return 0;
    
}
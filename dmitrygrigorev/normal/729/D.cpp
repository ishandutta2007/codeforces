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
vector<int> data;
int main(){
    int n, a, b, k;
    string v;
    cin >> n >> a >> b >> k;
    cin >> v;
    int counter = 0;
    for (int i=0;i<n;i++){
        if (v[i] == '0'){
            counter ++;
        }
        else{
            counter = 0;
        }
        if (counter >= b){
            data.push_back(i);
            counter = 0;
        }
    }
    int c = data.size() - a;
    cout << c + 1 << endl;
    for (int i=0;i<c;i++){
        cout << data[i] + 1 << " ";
    }
    cout << data[c] + 1 << endl;
    return 0;
}
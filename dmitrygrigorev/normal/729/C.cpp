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
vector <vector <int> > cars;
vector <int> zapr;
int s;
int tf(int toplivo){
    int time = 0;
    int len = zapr[0];
        int number = toplivo - len;
        if (number < 0){
            return -2;
        }
        else{
            if (number >= len){
                time += len;
            }
            else{
            time += number + 2 * (len - number);
            }
        }
    for (int i=1;i<zapr.size();i++){
        int len = zapr[i] - zapr[i - 1];
        int number = toplivo - len;
        if (number < 0){
            return -2;
        }
        else{
            if (number >= len){
                time += len;
            }
            else{
            time += number + 2 * (len - number);
            }
        }
    }
    len = s - zapr[zapr.size() - 1];
        number = toplivo - len;
        if (number < 0){
            return -2;
        }
        else{
            if (number >= len){
                time += len;
            }
            else{
            time += number + 2 * (len - number);
            }
        }
    return time;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n, k, t, ci, vi;
    cin >> n >> k >> s >> t;
    for (int i=0;i<n;i++){
        cin >> ci >> vi;
        vector<int> help;
        help.push_back(ci);
        help.push_back(vi);
        cars.push_back(help);
    }
    for (int i=0;i<k;i++){
        cin >> ci;
    zapr.push_back(ci);
    }
    sort(zapr.begin(), zapr.end());
    int right = max(s + 1, 1000000);
    int left = 0;
    while (right - left > 1){
        int m = (right + left) / 2;
        int result = tf(m);
        if (result > t | result == -2){
            left = m;
        }
        else{
            right = m;
        }
    }
    int bak = right;
    int answer = -1;
    for (int i = 0;i<n;i++){
        int money = cars[i][0];
        int bak1 = cars[i][1];
        if (bak1 >= bak){
            if (answer == -1){
                answer = money;
            }
            else{
                answer = min(answer, money);
            }
        }
    }
    cout << answer << endl;
    return 0;
}
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
vector <double> data;
vector <double> sums;
vector<double> cards;
int constante = 500000;
double second_const = 210000;
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    double ai;
    cin >> n;
    for (int i=0;i<n;i++){
        cin >> ai;
        data.push_back(ai);
    }
    sort(data.begin(), data.end());
    double summ = 0;
    for (int i=0;i<constante;i++){
        cards.push_back(0);
    }
    for (int i=0;i<n;i++){
        cards[data[i]] ++;
    }
    for (int i=0;i<constante;i++){
        summ += cards[i];
    sums.push_back(summ);
    }
    double answer = 0;
    for (int i=0;i<n;i++){
        if (data[i] != data[i-1]){
        double now = 0;
        double card = data[i];
        double counter = card;
        while (counter <= second_const){
            now += counter * (sums[counter + card - 1] - sums[counter - 1]);
            counter += card;
        }
        answer = max(answer, now);
            }
    }
    cout.precision(15);
    cout << answer << endl;
        return 0;
}
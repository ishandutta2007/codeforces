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
vector<double> fenwick;
double last;
double per;
double n;
double answer;
int f(int number){
    int a = number & (number + 1);
    return a;
}
void push(int number, double plus){
    while (number < n){
        fenwick[number] += plus;
        number = number | (number) + 1;
    }
}
double get(int i){
    double res = 0;
    while (i >= 0){
        res += fenwick[i];
        i = f(i) - 1;
    }
    return res;
}
int main(){
    answer = 0;
    int ai;
    cin >> n;
    last = 0;
    double kol = n * (n + 1) / 2;
    for (int i=0;i<n;i++){
        cin >> ai;
        fenwick.push_back(0);
        data.push_back(ai);
    }
    double middle = 0;
    for (int i=0;i<n;i++){
        double inv = get(data[n-i-1]-1);
        double ii = i;
        middle += ii * (ii + 1) / 4;
        answer += middle - (last + inv);
        last = last + inv;
        push(data[n-i-1]-1, i+1);
    }
    per = 0;
    for (int i=0;i<n;i++){
        fenwick[i] = 0;
    }
    for (int i=0;i<n;i++){
        per += i - get(data[i]-1);
        push(data[i] - 1, 1);
    }
    cout.precision(20);
    cout << per + answer / kol << endl;
    return 0;
}
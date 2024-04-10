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
long long n, k, c, cc;
long long start;
long long start1;
vector<long long> data;
long long result1(){
    long long ff = k / 2;
    long long ost = 1;
    long long counter = ff;
    long long counter1 = 0;
    while (counter > 0){
        if ((start - counter1) % c == 0){
            return 0;
        }
        ost = (ost * ((start - counter1) % c)) % c;
        counter --;
        counter1 += 2;
    }
    long long rar = 2;
    long long p = 1;
    while (rar <= k){
    long long ss = (k-1) / rar;
    counter = ss;
    counter1 = 1;
    start1 = data[(n-p) % (c-1)];
    while (counter > 0){
        if ((start1 - counter1) % c == 0){
            return 0;
        }
        ost = (ost * ((start1 - counter1) % c)) % c;
        counter -= 2;
        counter1 += 2;
    }
    rar = rar * 2;
    p++;
    }
    if (ost < 0){
        ost += c;
    }
    return ost;
}
long long result2(){
    long long s1 = ((n % (c-1)) * ((k-1) % (c-1))) % (c-1);
    long long sas = 2;
    while (sas <= (k-1)){
        s1 -= (((k-1) / sas) % (c-1));
        sas = sas * 2;
    }
    long long s3 = s1 % (c-1);
    if (s3 < 0){
        s3 += c-1;
    }
    long long oo = 1;
    for (int i=0;i<s3;i++){
        oo = (oo * 2) % c;
    }
    return oo;
}
int main(){
    c = pow(10, 6) + 3;
    cin >> n >> k;
    if (n <= 100){
        if (pow(2, n) <= (k-1)){
            cout << 1 << " " << 1 << endl;
            return 0;
        }
    }
    long long st = 1;
    for (int i=0;i<c-1;i++){
        data.push_back(st);
        st = (st * 2) % c;
    }
    st = 1;
    for (int i=0;i<n%(c-1);i++){
        st = (st * 2) % c;
    }
    start = st - 1;
    st = 1;
    for (int i=0;i<n%(c-1) - 1;i++){
        st = (st * 2) % c;
    }
    start1 = st - 1;
    long long second = result2();
    long long first = result1();
    long long first1 = (second - first) % c;
    if (first1 < 0){
        first1 += c;
    }
    cout << first1 << " " << second << endl;
    return 0;
}
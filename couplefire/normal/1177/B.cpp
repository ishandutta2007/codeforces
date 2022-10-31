#include <bits/stdc++.h>
using namespace std;

int main() {
 long long k;
 cin >> k;
 int i = 1;
 long long num = 0;
 while(true){
   long long temp = num;
   num += i*pow(10, i-1)*9;
   i++;
   if(num >= k){
     num = temp;
     i--;
     break;
   }
 }
 long long dif = k-num-1;
 long long n = dif/i;
 long long r = dif % i;
 long long number = pow(10, i-1) + n;
 string str = to_string(number);
 cout << str[r] << endl;
}
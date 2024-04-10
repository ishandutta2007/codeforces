#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,m;
string s1,s2;
int a[256],b[256];
bool flag;
int main(int argc, char const *argv[]) {

 getline(cin,s1);
 for(int i=0;i<(int)s1.size();i++) {
   a[s1[i]]++;
 }
 getline(cin,s2);
 for(int i=0;i<(int)s2.size();i++) {
   b[s2[i]]++;
 }
 for(int i='A';i<='z';i++) {
   if(b[i] > a[i]) {
     flag = 1;
     break;
   }
 }
 if(flag==1) {
   std::cout << "NO" << '\n';
 }
 else {
   std::cout << "YES" << '\n';
 }
  return 0;
}
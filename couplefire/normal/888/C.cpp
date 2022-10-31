#include <bits/stdc++.h>
using namespace std;

bool work(string str, int k);
int bs(string str);

int main() {
  cout << fixed;
  string str;
  cin >> str;
  cout << (int) bs(str) << endl;
}

bool work(string str, int k){
  int arr[26];
  int lastseen[26];
  for(int i = 0; i<26; i++){
    arr[i] = 1;
    lastseen[i] = -1;
  }
  for(int i = 0; i<str.length(); i++){
    if(i-lastseen[str[i]-'a'] > k){
      arr[str[i]-'a'] = 0;
    }
    else{
      lastseen[str[i]-'a'] = i;
    }
  }
  for(int i = 0; i<26; i++){
    if(arr[i] == 1 && str.length()-lastseen[i] <= k){
      return true;
    }
  }
  return false;
}

int bs(string str){
  int lower = 1;
  int upper = str.length();
  while(lower <= upper){
    int mid = (lower+upper)/2;
    if(work(str, mid) == true && work(str, mid-1) == false) return mid;
    else if(work(str, mid) == false) lower = mid+1;
    else if(work(str, mid-1) == true) upper = mid-1;
  }
  return -1;
}
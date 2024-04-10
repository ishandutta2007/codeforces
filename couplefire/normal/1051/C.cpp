#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];
  int cnt[101] = {0};
  int pos[101] = {0};
  char belong[n];
  for(int i = 0; i<n; i++){
    belong[i] = 'A';
    cin >> arr[i];
    cnt[arr[i]]++;
    pos[arr[i]] = i;
  }
  bool allone = true;
  int num = 0;
  int firstnonone = -1;
  bool good = true;
  for(int i = 0; i<101; i++){
    if(cnt[i] != 1 && cnt[i] != 0 && cnt[i] != 2){
      allone = false;
      firstnonone = i;
    }
    else if(cnt[i] == 1){
      num++;
      belong[pos[i]] = (good) ? 'A' : 'B';
      good = 1-good;
    }
  }
  if(allone == true && num % 2 == 1){
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  if(firstnonone != -1 && num % 2 == 1){
    belong[pos[firstnonone]] = 'B';
  }
  for(int i = 0; i<n; i++){
    cout << belong[i];
  }
  cout << endl;

}
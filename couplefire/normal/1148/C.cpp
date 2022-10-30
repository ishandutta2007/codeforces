#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int pos[n+1];
  int arr[n+1];
  for(int i = 1; i<=n; i++){
    int a;
    scanf("%d", &a);
    pos[a] = i;
    arr[i] = a;
  }
  queue<pair<int, int>> q;
  for(int i = 1; i<=n; i++){
    if(arr[i] == i) continue;
    int temp = pos[i];
    if(i <= n/2 && temp <= n/2){
      q.push(make_pair(temp, n));
      q.push(make_pair(i, n));
      pos[i] = i;
      pos[arr[n]] = temp;
      pos[arr[i]] = n;
      int t = arr[i];
      arr[i] = i;
      arr[temp] = arr[n];
      arr[n] = t;
    }
    else if(i > n/2 && temp > n/2){
      q.push(make_pair(temp, 1));
      q.push(make_pair(1, i));
      q.push(make_pair(temp, 1));
      pos[i] = i;
      pos[arr[i]] = temp;
      int t = arr[i];
      arr[i] = i;
      arr[temp] = t;
    }
    else{
      if(temp - i >= n/2){
        q.push(make_pair(temp, i));
        pos[i] = i;
        pos[arr[i]] = temp;
        int t = arr[i];
        arr[i] = i;
        arr[temp] = t;
        continue;
      }
      q.push(make_pair(temp, 1));
      q.push(make_pair(1, n));
      q.push(make_pair(i, n));
      q.push(make_pair(temp, 1));
      pos[i] = i;
      pos[arr[i]] = n;
      pos[arr[n]] = temp;
      int t = arr[i];
      arr[i] = i;
      arr[temp] = arr[n];
      arr[n] = t;
    }
  }
  cout << q.size() << endl;
  while(!q.empty()){
    printf("%d %d\n", q.front().first, q.front().second);
    q.pop();
  }
}
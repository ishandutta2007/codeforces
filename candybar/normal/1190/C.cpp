#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>
#define maxn 100015
using namespace std;
typedef long long ll;

int n,k;
vector <int> up,down;
char s[maxn];
int main(){
  scanf("%d%d",&n,&k);
  scanf("%s",s);
  for(int i = 0;i < n;i++){
    if(s[i] == '0') down.push_back(i);
    else up.push_back(i);
  }
  if(up.empty() || down.empty()){
    puts("tokitsukaze");
    return 0;
  }
  int a = up.size(), b = down.size();
  if(up[a - 1] - up[0] + 1 <= k || down[b - 1] - down[0] + 1 <= k){
    puts("tokitsukaze");
    return 0;
  }
  bool ok = false;
  for(int i = 0;i + k - 1 < n;i++){
    int fir1 = down[0] < i ? down[0] : *lower_bound(down.begin(),down.end(),i + k);
    int lst1 = down[b - 1] >= i + k ? down[b - 1] : *(lower_bound(down.begin(),down.end(),i) - 1);
    if(lst1 - fir1 + 1 > k) ok = true;
    fir1 = up[0] < i ? up[0] : *lower_bound(up.begin(),up.end(),i + k);
    lst1 = up[a - 1] >= i + k ? up[a - 1] : *(lower_bound(up.begin(),up.end(),i) - 1);
    if(lst1 - fir1 + 1 > k) ok = true;
  }
  if(ok){
    puts("once again");
  }else{
    puts("quailty");
  }
  return 0;
}
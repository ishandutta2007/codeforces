#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <utility>

using namespace std;
typedef long long ll;

vector <int> ans;
void query(char* s){
  printf("? %s\n",s);
  fflush(stdout);
  int k;
  scanf("%d",&k);
  if(k == -1) exit(0);
  ans.resize(k);
  for(int i = 0;i < k;i++) scanf("%d",&ans[i]);
}
void guess(char* s){
  printf("! %s\n",s);
  fflush(stdout);
  int ret;
  scanf("%d",&ret);
  if(!ret) exit(0);
}
#define maxn 55
int t,n;
char s[maxn],q[maxn];
void bf4(int x){// after asking "CC","CH","CO" and "OH".
  if(x == 5){
    query(q + 1);
    if(ans.size()) memcpy(s,q,sizeof(q));
    return;
  }
  if(s[x]){
    q[x] = s[x];
    bf4(x + 1);
  }else if(x == 4){
    q[x] = 'C';
    bf4(x + 1);
    q[x] = 'H';
    bf4(x + 1);
    q[x] = 'O';
    bf4(x + 1);
  }else{
    q[x] = 'H';
    bf4(x + 1);
    q[x] = 'O';
    bf4(x + 1);
  }
}
void solve4(){
  query("CC");
  for(int i = 0;i < (int)ans.size();i++)
    s[ans[i]] = s[ans[i] + 1] = 'C';
  query("CH");
  for(int i = 0;i < (int)ans.size();i++)
    s[ans[i]] = 'C', s[ans[i] + 1] = 'H';
  query("CO");
  for(int i = 0;i < (int)ans.size();i++)
    s[ans[i]] = 'C', s[ans[i] + 1] = 'O';
  query("OH");
  for(int i = 0;i < (int)ans.size();i++)
    s[ans[i]] = 'O', s[ans[i] + 1] = 'H';
  for(int i = 1;i <= n;i++){
    if(s[i]){
      bf4(1);
      guess(s + 1);
      return;
    }
  }
  query("HHH");
  if(ans.size() == 2){
    guess("HHHH");
    return;
  }
  if(ans.size() == 1){
    query("HHHO");
    if(ans.size()) guess("HHHO");
    else guess("HHHC");
    return;
  }
  query("OOO");
  if(ans.size() == 2){
    guess("OOOO");
    return;
  }
  if(ans.size() == 1){
    if(ans[0] == 1) guess("OOOC");
    else guess("HOOO");
    return;
  }
  query("HHOO");
  if(ans.size()){
    guess("HHOO");
    return;
  }
  query("HHOC");
  if(ans.size()){
    guess("HHOC");
    return;
  }
  guess("HOOC");
}
void solveNormal(){
  query("CC");
  for(int i = 0;i < (int)ans.size();i++)
    s[ans[i]] = s[ans[i] + 1] = 'C';
  query("CH");
  for(int i = 0;i < (int)ans.size();i++)
    s[ans[i]] = 'C', s[ans[i] + 1] = 'H';
  query("CO");
  for(int i = 0;i < (int)ans.size();i++)
    s[ans[i]] = 'C', s[ans[i] + 1] = 'O';
  query("OH");
  for(int i = 0;i < (int)ans.size();i++)
    s[ans[i]] = 'O', s[ans[i] + 1] = 'H';
  query("HO");
  for(int i = 0;i < (int)ans.size();i++)
    s[ans[i]] = 'H', s[ans[i] + 1] = 'O';
    
//  for(int i = 1;i <= n;i++){
//    cout << int(s[i]) << " ";
//  }
//  cout << endl;
//  system("pause");
  
  for(int i = 1;i < n;i++) if(!s[i] && s[i - 1]) s[i] = s[i - 1];
  for(int i = n - 1;i >= 1;i--)
    if(!s[i] && s[i + 1] && s[i + 1] != 'C') s[i] = s[i + 1];
  memcpy(q,s,sizeof(s));
  for(int i = 1;i < n;i++) if(!q[i]) q[i] = 'H';
  q[n] = 0;
  query(q + 1);
  if(ans.size() && ans[0] == 1){
    for(int i = 1;i < n;i++) if(!s[i]) s[i] = 'H';
  }else{
    for(int i = 1;i < n;i++) if(!s[i]) s[i] = 'O';
  }
  if(s[n]){
    guess(s + 1);
    return;
  }
  memcpy(q,s,sizeof(s));
  q[n] = 'C';
  query(q + 1);
  if(ans.size()) s[n] = 'C';
  else s[n] = s[n - 1];
  guess(s + 1);
}
int main(){
  scanf("%d",&t);
  while(t--){
    scanf("%d",&n);
    memset(s,0,sizeof(s));
    memset(q,0,sizeof(q));
    if(n == 4) solve4();
    else solveNormal();
  }
  return 0;
}
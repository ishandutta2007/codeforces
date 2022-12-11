#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=4500;
int T;char s[N];
void solve(){
  scanf("%s",s+1);
  int len=strlen(s+1);
  if(len==2)putchar(s[2]),puts("");
  else {
    char mn=127;
    for(int i=1;i<=len;i++)mn=min(mn,s[i]);
    putchar(mn);puts("");
  }
}
int main(){
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}
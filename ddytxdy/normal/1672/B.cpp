#include<bits/stdc++.h>
using namespace std;
const int N=2e5+50;
int T,n,num;char s[N];
void solve(){
  scanf("%s",s+1);
  n=strlen(s+1);num=0;
  for(int i=1;i<=n;i++){
    if(s[i]=='A')num++;
    else num--;
    if(num<0){puts("NO");return;}
  }
  if(s[n]=='B')puts("YES");
  else puts("NO");
}
int main(){
  scanf("%d",&T);
  while(T--)solve();
  return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N=(int)4e5+7;
int n;
int x[N];
int m;
int stops[N];
int f[N];
int value[N];
int rep;
int cz;
ll sol=-1,cr;

void proc(){
  if(cz!=n)return;
  if(sol!=-1&&sol!=cr){
    cout<<"-1\n";
    exit(0);
  }
  sol=cr;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin>>n;
  cz=n;
  rep=2*n-1;
  for (int i=1;i<=n;i++){
    cin>>x[i];
  }
  cin>>m;
  for (int i=1;i<=m;i++){
    cin>>stops[i];
    cz-=(f[stops[i]]==0);
    f[stops[i]]--;
    cz+=(f[stops[i]]==0);
  }
  rep=0;
  for (int i=1;i<=n;i++)value[rep++]=i;
  for (int i=n-1;i>1;i--)value[rep++]=i;
  assert(rep==2*n-2);
  for (int i=0;i<m;i++){
    cz-=(f[value[i%rep]]==0);
    f[value[i%rep]]++;
    cz+=(f[value[i%rep]]==0);
  }
  for (int i=0;i<m-1;i++){
    cr+=abs(x[value[(i)%rep]]-x[value[(i+1)%rep]]);
  }
  proc();
  for (int i=1;i<rep;i++) {
    cr-=abs(x[value[(i+rep-1)%rep]]-x[value[(i)%rep]]);
    cz-=(f[value[(i+rep-1)%rep]]==0);
    f[value[(i+rep-1)%rep]]--;
    cz+=(f[value[(i+rep-1)%rep]]==0);
    cz-=(f[value[(i+m-1)%rep]]==0);
    f[value[(i+m-1)%rep]]++;
    cr+=abs(x[value[(i+m-1)%rep]]-x[value[(i+m-2)%rep]]);
    cz+=(f[value[(i+m-1)%rep]]==0);
    proc();
  }
  cout<<sol<<"\n";
}
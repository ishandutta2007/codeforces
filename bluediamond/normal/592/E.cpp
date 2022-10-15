#include <bits/stdc++.h>

bool home=1;

using namespace std;

typedef long double ld;
#define int long long

const int N=345678+7;
const ld pi=(ld)2*acos((ld)0);
const ld eps=1e-18;
int n;
int c;
int d;
int x[N];
int y[N];
int eq[N];
int tot[N];
int wa[N];
ld a[N];
ld b[N];

signed main() {
#ifdef ONLINE_JUDGE
  home=0;
#endif

  if(home) {
    freopen("I_am_iron_man","r",stdin);
   /// freopen ("output.txt","w",stdout);
  }
  else{
    ios::sync_with_stdio(0);cin.tie(0);
  }


  cin>>n>>c>>d;
  for(int i=1;i<=n;i++){
    cin>>x[i]>>y[i];
    x[i]-=c;
    y[i]-=d;
    a[i]=atan2((ld)y[i],(ld)x[i]);
  }
  sort(a+1,a+n+1);
  for(int i=1;i<=n;i++){
    b[i]=a[i]-pi;
  }
  sort(b+1,b+n+1);

  {
    int j=0;
    for(int i=1;i<=n;i++){
      while(j+1<=n&&a[j+1]<b[i]-eps) j++;
      eq[i]-=j;
    }
    j=n+1;
    for(int i=n;i>=1;i--){
      while(j-1>=1&&a[j-1]>b[i]+eps) j--;
      eq[i]+=j-1;
    }
    j=0;
    for(int i=1;i<=n;i++){
      while(j+1<i&&a[i]-a[j]>=pi) j++;
      tot[i]-=j;
    }

    j=n+1;

    for(int i=n;i>=1;i--){
      while(j-1>=i&&a[j-1]-a[i]>=pi-eps) j--;
      tot[i]+=j-1;
    }
    j=0;
    for(int k=1;k<=n;k++){
      while(j+1<=n&&a[j+1]<=b[k]-eps){
        j++;
      }
      wa[k]+=j;
    }
    j=0;
    for(int k=1;k<=n;k++){
      while(j+1<=n&&a[j+1]<=b[k]-pi){
        j++;
      }
      wa[k]-=j;
    }
  }
  long long sol=0,pref=0;

  int ptr=0,ptr2=0;


  for (int k=1;k<=n;k++){
    while(ptr+1<=n&&a[ptr+1]<=b[k]-eps){
      ptr++;
      while(ptr2+1<ptr&&a[ptr2+1]<=pi-eps+a[ptr]) ptr2++;
      pref+=tot[ptr]-ptr-ptr2;
    }

    sol+=pref;
    sol-=wa[k]*(long long)eq[k];
  }

  cout<<sol<<"\n";
}
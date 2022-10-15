#include <bits/stdc++.h>


using namespace std;

bool home = 1;

const int N=(int) 4e5+7;
const int INF=(int)1e9;
int n,s[N],b1[N],b2[N];
string str;


signed main() {
#ifdef ONLINE_JUDGE
  home = 0;
#endif
  if (home) {
    freopen("iron_man.txt", "r", stdin);
  }
  if (!home) {
    ios::sync_with_stdio(0), cin.tie(0);
  }

  int tt;
  cin>>tt;
  while(tt--){
    cin>>str;
    n=(int)str.size();
    for (int i=1;i<=n;i++){
      if(str[i-1]=='0'){
        s[i]=-1;
      }else{
        s[i]=+1;
        assert(str[i-1]=='1');
      }
      s[i]+=s[i-1];
    }

    for (int i=0;i<=n;i++){
      assert(0<=s[i]+n&&s[i]+n<=2*n);
    }

    for (int i=0;i<=2*n;i++){
      b1[i]=-INF;
      b2[i]=-INF;
    }
    for (int l=0;l<=n;l++){
      b1[s[l]+n]=max(b1[s[l]+n],-l+s[l]);
      b2[s[l]+n]=max(b2[s[l]+n],-l-s[l]);
    }

    for (int i=1;i<=2*n;i++){
      b1[i]=max(b1[i],b1[i-1]);
    }
    for (int i=2*n-1;i>=0;i--){
      b2[i]=max(b2[i+1],b2[i]);
    }

    int print=-INF;
    for (int r=0;r<=n;r++){
      int sol1=-INF,sol2=-INF;

      int c1=-INF,c2=-INF;


      if(s[r]+n-1>=0){
        c1=b1[s[r]+n-1];
      }

      if(s[r]+n+1<=2*n){
        c2=b2[s[r]+n+1];
      }

      sol1=c1;
      sol2=c2;


      assert(sol1==c1);
      assert(sol2==c2);

      sol1+=r-s[r];
      sol2+=r+s[r];
      assert(sol1%2==0);
      assert(sol2%2==0);
      print=max(print,sol1);
      print=max(print,sol2);
    }
    assert(print%2==0);

    cout<<print/2<<"\n";
  }

  return 0;
}
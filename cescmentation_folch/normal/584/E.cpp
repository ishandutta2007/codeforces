#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

#define For(i,a,f) for(int i = a; i < f; ++i)
#define foR(i,a,f) for(int i = a; i > f; --i)


int main(){
  int n;
  scanf("%d",&n);

  int ana[n+1];
  int pos[n+1];

  
  
//   cerr<<1<<endl;
  for(int i = 1; i <= n; ++i){
    int x;
    scanf("%d",&x);

    pos[i] = x;
  }

for(int i = 1; i <= n; ++i){
//     cerr<<i<<endl;
    int x;
    scanf("%d",&x);
    ana[x] = i;

  }
//   cerr<<2<<endl;

vi A,B;
  int r = 0;


for(int u = 0; u <= n/2; ++u){
    for(int i = n-1; i > 0; --i){
        if(ana[pos[i]] == i) continue;
        int k = i;
//  cerr << k << endl;
        
    for(int j = k+1; j <= n; ++j){
        if(ana[pos[j]] == j) continue;
        int x = pos[k];
        int y = pos[j];
        if(ana[x] >= j and ana[y] <= k){
//      cerr << j << endl;
        pos[k] = y;
        pos[j] = x;
        A.push_back(k);
        B.push_back(j);
        r += abs(k-j);
        k = j;
        break;
        }
    }
         
    }
    for(int i = 1;i < n; ++i){
        if(ana[pos[i]] == i) continue;
        int k = i;
//  cerr << k << endl;
        
    for(int j = k+1; j <= n; ++j){
        if(ana[pos[j]] == j) continue;
        int x = pos[k];
        int y = pos[j];
        if(ana[x] >= j and ana[y] <= k){
//      cerr << j << endl;
        pos[k] = y;
        pos[j] = x;
        A.push_back(k);
        B.push_back(j);
        r += abs(k-j);
        k = j;
        break;
        }
    }
         
    }
}
  
  cout<<r<<endl;
    cout<<A.size()<<endl;
    for(int i = 0;i < A.size();++i) printf("%d %d\n",A[i],B[i]);
}
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

char dif(char a, char b){
  if(a != 'a' and b != 'a') return 'a';
  if(a != 'b' and b != 'b') return 'b';
  return 'c';
}

int main(){
  int n,t;
  cin>>n>>t;
  string a,b;
  cin>>a>>b;
  int c = 0;
  for(int i = 0; i < n; ++i){
    if(a[i] == b[i]) ++c;
  }
  if(t < n-(c+(n-c)/2)){
    cout<<-1<<endl;
  }
  else{
    if(n-c <= t){
      string z = a;
      t = n-t;
      for(int i = 0;i < n;++i){
	if(a[i] != b[i] or t <= 0){
	  z[i] = dif(a[i],b[i]);
	}
	else --t;
      }
      cout<<z<<endl;
    }
    else {
      string z = a;
      t = n-t-c;
      int t2 = t;
      for(int i = 0; i < n; ++i){
	if(a[i] != b[i]){
	  if(t > 0){ 
	    z[i] = a[i];
	    --t;
	  }
	  else if(t2 > 0){
	    z[i] = b[i];
	    --t2;
	  }
	  else z[i] = dif(a[i],b[i]);
	} 
      }
      cout<<z<<endl;
    }
  }
}
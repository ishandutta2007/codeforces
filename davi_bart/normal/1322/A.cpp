#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;
    string a;
    cin>>a;
    int k=0;
    for(int i=0;i<N;i++){
      if(a[i]=='(')k++;
    }
    if(k+k!=N){
      cout<<-1;
      return 0;
    }
    int ap=0,ch=0;
    int last=-1;
    int tot=0;
    bool kk=0;
    for(int i=0;i<N;i++){
      if(a[i]==')')ch++;
      else ap++;
      if(ap<ch)kk=1;
      if(ap>=ch){
          if(kk){
            tot+=i-last;
            kk=0;
          }
          last=i;
      }
    }
    cout<<tot;
    return 0;
}
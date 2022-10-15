#include <bits/stdc++.h>

using namespace std;

const int N=1000000;
int n,vreau[N+5];
int v[N+5],poz[N+5];
int cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>vreau[i];
        v[i]=poz[i]=i;
    }
    for(int i=1;i<=n;i++){
        if(vreau[i]==v[i])
            continue;
      ///  cout<<i<<"\n";
        int j=poz[vreau[i]];
        swap(v[i],v[j]);
        swap(poz[v[i]],poz[v[j]]);
        cnt++;
    }
    ///cout<<cnt<<"\n";
    cnt=n-cnt;
    if(cnt%2==0){
        cout<<"Petr\n";
    }
    else{
        cout<<"Um_nik\n";
    }
    return 0;
}
/**
**/
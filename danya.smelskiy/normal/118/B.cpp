#include <bits/stdc++.h>
using namespace std;
int n,k;
int main(){
    cin>>n;
    k=n+1;
    for (int i=0;i<=n;++i){
        for (int j=n-i;j>0;--j)
            cout<<"  ";
        for (int j=0;j<=i;++j){ cout<<j; if (i!=0) cout<<" ";}
        for (int j=i-1;j>=0;--j){ cout<<j;
        if (j>0) cout<<" ";
        }
      //  cout<<".";
        cout<<endl;
    }
    for (int i=n-1;i>=0;--i){
        for (int j=n-i;j>0;--j)
            cout<<"  ";
        for (int j=0;j<=i;++j){ cout<<j; if (i!=0) cout<<" ";}
        for (int j=i-1;j>=0;--j) {cout<<j;
            if (j>0) cout<<" ";
        }
        //cout<<".";
        cout<<endl;
    }
}
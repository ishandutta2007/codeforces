#include <bits/stdc++.h>
using namespace std;
int n,x;
int a[5];
int main(){
    cin>>n;
    x=n+1;
    while (true){
        bool t=false;
        a[1]=x%10; a[2]=(x/10)%10; a[3]=(x/100)%10; a[4]=x/1000;
        for (int i=1;i<=4;++i)
            for (int j=1;j<=4;++j)
            if (i!=j && a[i]==a[j]) t=true;
        if (t==false){
            cout<<x;
        return 0;
        }
        ++x;
    }
}
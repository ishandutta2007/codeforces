#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    cin>>n;
    if (n<=2) cout<<"1"<<endl<<"1";
    else if (n==3) cout<<"2"<<endl<<"1 3";
    else {
        cout<<n<<endl;
        for (int i=n/2+n%2;i>0;--i)
            cout<<i*2-1<<" ";
        for (int i=n/2;i>0;--i)
            cout<<i*2<<" ";
    }
}
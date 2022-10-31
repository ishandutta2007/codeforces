#include <bits/stdc++.h>
using namespace std;


int n;

int main(){
    cin>>n;
    if (n==1)  {
        cout<<"1 1"<<'\n'<<"1";
        return 0;
    }
    --n;
    n*=4;
    cout<<n<<" "<<2<<'\n';
    cout<<"2 4";
}
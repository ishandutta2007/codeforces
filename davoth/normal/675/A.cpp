#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    long long a,b,c;
    cin>>a>>b>>c;
    if((((a>b&&c<0)||(a<b&&c>0))&&((b-a)%c==0))||(a==b)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int r,d,n,ans=0;
    cin>>r>>d>>n;
    int x[n],y[n],rl[n];
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i]>>rl[i];
    }
    for(int i=0;i<n;i++){
        if(sqrt(x[i]*x[i]+y[i]*y[i])+rl[i]<=r&&sqrt(x[i]*x[i]+y[i]*y[i])-rl[i]>=r-d){
           ans++;
        }
    }
    cout<<ans;
    return 0;
}
#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int main(){
    int n;
    cin>>n;
    int x=0,y=0,z=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        x+=temp;
        cin>>temp;
        y+=temp;
        cin>>temp;
        z+=temp;
    }
    if(x==0&&y==0&&z==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
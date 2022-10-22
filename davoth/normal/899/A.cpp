#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    int t=0,o=0;
    for(int i=0;i<n;i++){
        if(a[i]==2) t++;
        else o++;
    }
    int cnt=0;
    while(t&&o){
        t--;
        o--;
        cnt++;
    }
    while(o>2){
        o-=3;
        cnt++;
    }
    cout<<cnt;
    return 0;
}
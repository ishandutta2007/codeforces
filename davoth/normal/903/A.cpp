#include <iostream>
#include <vector>
using namespace std;
void d(int a){
    while(a>=0){
        if(a%3==0||a==0){
            cout<<"YES"<<"\n";
            return;
        }
        a-=7;
    }
    cout<<"NO"<<"\n";
    return;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        d(temp);
    }
    return 0;
}
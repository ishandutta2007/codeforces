#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,b=0,c=0;
    cin>>n;
    int a[n];
    int m[]={31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<36;i++){
        if(a[0]==m[i]||(m[i]==28&&a[0]==29)){
            for(int o=i;o<36;o++){
                if(a[c]==m[o]){
                    c++;
                }else if(m[o]==28&&a[c]==29&&b==0){
                    c++;
                    b=1;
                }else{
                    c=0;
                    b=0;
                    break;
                }
                if(c==n){
                    cout<<"Yes";
                    return 0;
                }
            }
        }
    }
    cout<<"No";
    return 0;
}
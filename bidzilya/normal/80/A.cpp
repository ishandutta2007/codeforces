#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a,b,k,i,j;
    bool bol;
    int arr[20];
    
    cin>>a>>b;
    k=0;
    for (i=2;i<=50;i++){
        bol=true;
        for (j=2;j<=round(sqrt(i));j++){
            if (i%j==0){
                        bol=false;
                        break;
                        }
                        }
        if (bol==true){
                       k++;
                       arr[k]=i;
                       }
                       }
    for (j=1;j<=k;j++){
        if (arr[j]==a){i=j; break;}
        }
    if (arr[i+1]==b){cout<<"YES";} else {cout<<"NO";}
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

string a="codeforces";
int c[10];

int main(){
    long long k;
    cin>>k;
    long long f=1;
    for(int i=0;i<10;i++)c[i]=1;
    while(f<k){
        for(int i=0;i<10;i++){
            f/=c[i];
            c[i]++;
            f*=c[i];
            if(f>=k)break;
        }
    }
    for(int i=0;i<10;i++)while(c[i]--)cout<<a[i];
    return 0;
}
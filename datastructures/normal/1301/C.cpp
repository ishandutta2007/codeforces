#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int t,n,m;
signed main(){
    cin>>t;
    while(t--){
        cin>>n>>m;
        int nn=n;
        n-=m,m++;
        int len1,len2,num1,num2;
        len1=n/m;
        len2=len1+1;
        num2=n%m;
        num1=m-num2;
        cout<<(nn*(nn+1)/2)-num1*(len1*(len1+1)/2)-num2*(len2*(len2+1)/2)<<endl;
    }
    return 0;
}
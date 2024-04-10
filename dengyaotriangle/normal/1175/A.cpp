#include<iostream>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdio>

using namespace std;

int main(){
    int t;
    cin>>t;
    long long n,k;
    while(t--){
        cin>>n>>k;
        long long cnt=0;
        while(n!=0){
            if(n%k==0){
                n/=k;
                cnt++;
            }else{
                cnt+=n%k;
                n-=n%k;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
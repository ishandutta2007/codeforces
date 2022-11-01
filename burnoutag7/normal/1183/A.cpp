#include<bits/stdc++.h>
using namespace std;

int n;

bool is(int x){
    int clo=x,cnt=0;
    while(clo>0){
        cnt+=clo%10;
        clo/=10;
    }
    return cnt%4==0;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(!is(n))n++;
    cout<<n<<endl;

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int n;
int a[200005];
int l,r;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    if(!(n&1)){
        cout<<"NO"<<endl;
        return 0;
    }
    int l=1,r=n<<1;
    for(int i=1;i<=n;i++){
        if(i&1){
            a[i]=l;
            a[i+n]=l+1;
            l+=2;
        }else{
            a[i]=r;
            a[i+n]=r-1;
            r-=2;
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=(n<<1);i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;

    return 0;
}
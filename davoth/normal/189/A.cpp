#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;
int mx(int a,int b){
    if(a>b) return a;
    else return b;
}
int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    int l[4001]={0};
    l[a]=1;
    l[b]=1;
    l[c]=1;
    for(int i=0;i<4001;i++){
        if(a<=i&&b<=i&&c<=i){
            int temp=mx(mx(l[i-c],l[i-b]),l[i-a]);
            if(temp>0) l[i]=mx(temp+1,l[i]);
        }else if(a>i&&b<=i&&c<=i){
            int temp=mx(l[i-c],l[i-b]);
            if(temp>0) l[i]=mx(temp+1,l[i]);
        }else if(b>i&&a<=i&&c<=i){
            int temp=mx(l[i-c],l[i-a]);
            if(temp>0) l[i]=mx(temp+1,l[i]);
        }else if(c>i&&b<=i&&a<=i){
            int temp=mx(l[i-a],l[i-b]);
            if(temp>0) l[i]=mx(temp+1,l[i]);
        }else if(a>i&&b>i&&c<=i&&l[i-c]>0){
                l[i]=mx(l[i-c]+1,l[i]);
        }else if(c>i&&b>i&&a<=i&&l[i-a]>0){
                l[i]=mx(l[i-a]+1,l[i]);
        }else if(a>i&&c>i&&b<=i&&l[i-b]>0){
                l[i]=mx(l[i-b]+1,l[i]);
        }
    }
    cout<<l[n];
    return 0;
}